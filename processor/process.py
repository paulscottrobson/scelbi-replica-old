#
#		8008 definition processor.
#
import re,sys

class Instruction:
	def __init__(self,definition):
		m = re.match('^([0-9A-F\\-\\,]+)\\s+(\\d+)\\s+\\"(.*)\\"\\s*$',definition)
		assert m is not None
		r = m.group(1)
		r = r if len(r) >= 5 else r + "-" + r
		r = r if len(r) == 7 else r + ",1"
		self.first = int(r[:2],16)
		self.last = int(r[3:5],16)
		self.step = int(r[-1])
		self.cycles = int(m.group(2))
		self.mnemonic = m.group(3).upper()
		self.phases = []
		#print(self.first,self.last,self.step,self.cycles,self.mnemonic)

	def addPhase(self,phase):
		self.phases.append(phase)

	def getMnemonics(self,mnemonicList):
		n = self.first
		while n <= self.last:
			assert mnemonicList[n] is None			
			mnemonicList[n] = self.process(self.mnemonic,n)
			n = n + self.step

	def process(self,s,opcode):
		s = s.replace("@S","ABCDEHLM"[opcode & 7])
		s = s.replace("@R","ABCDEHLM"[(opcode >> 3) & 7])
		s = s.replace("@C",["NC","NZ","P","PO","C","Z","M","PE"][(opcode >> 3) & 7])
		s = s.replace("@P","{0:02X}".format((opcode >> 1) & 0x1F))
		s = s.replace("@X","{0:02X}".format(opcode & 0x38))
		if s.find("@T") >= 0:
			cc = (opcode >> 3) & 7
			test = ["Carry != 0","pszValue == 0","(pszValue & 0x80) != 0","__IsParityEven()"][cc & 3]
			if (cc < 4):
				test = "!("+test+")"
			s = s.replace("@T",test)
		return s

	def render(self,codes):
		n = self.first
		while n <= self.last:
			mnemonic = self.process(self.mnemonic,n)
			rcode = "case 0x{0:02x}: /**** {1} ****/\n".format(n,mnemonic.lower())
			for p in range(0,len(self.phases)):
				rcode = rcode + "    {1} (phase == {0}) {{\n".format(p+1,"if" if p == 0 else "else if")
				code = self.phases[p].render(n,self)
				if p == 0:
					code = code + "; Cycles += {0};".format(self.cycles)
				nextPhase = p+2 if p != len(self.phases)-1 else 0
				code = code + "; phase = {0};".format(nextPhase)
				for c in code.split(";"):
					c = c.strip()
					if c != "":
						rcode = rcode + "        "+c+";\n"
				rcode = rcode + "    }\n"
			codes[n] = rcode + "    break;\n\n"
			n = n + self.step

class Phase:
	def __init__(self,definition):
		m = re.match("^([0\\*][0\\*])\\s+\\[([\\w\\(\\)\\,\\@\\<\\s\\d\\|\\-]+)\\]\\s+(.+)$",definition)
		assert m is not None
		self.status = m.group(1).replace("*","1")
		self.display = m.group(2).split(",")
		assert len(self.display) == 2
		self.code = m.group(3)
		#print(self.status,self.display,self.code)			

	def render(self,opcode,instruction):
		code = self.code+";DISPLAY({0},{1},{2},{3});".format(self.status[0],self.status[1],self.display[0],self.display[1])
		code = instruction.process(code,opcode)
		return code

src = [x.replace("\t"," ") for x in open("8008.def").readlines()]
src = [x.rstrip() for x in src if x.rstrip() != "" and x[0] != "#"]

open("__8008include.h","w").write("\n".join(x[1:] for x in src if x[0] == ':'))
src = [x for x in src if x[0] != ':']

currentInstruction = None
instructions = []

for s in src:
	if s[0] != ' ':
		currentInstruction = Instruction(s)
		instructions.append(currentInstruction)
	else:
		phase = Phase(s.strip())
		currentInstruction.addPhase(phase)

mnemonics = [None] * 256
for instr in instructions:
	instr.getMnemonics(mnemonics)
for i in range(0,256):
	if mnemonics[i] is None:
		mnemonics[i] = "DB {0:02X}".format(i)

open("__8008mnemonics.h","w").write(",".join('"'+x.lower()+'"' for x in mnemonics))

codes = [ None ] * 256
for instr in instructions:
	s = instr.render(codes)

h = open("__8008cpuphases.h","w")
for c in codes:
	if c is not None:
		h.write(c)
h.close()		