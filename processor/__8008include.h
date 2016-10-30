#define FETCH()  MA = PC;PC++;READ()
#define ADD(a,b)  temp16 = A + (a) + (b);pszValue = temp16 & 0xFF;Carry = (temp16 >> 8) & 1
#define SUB(a,b)  temp16 = A - (a) - (b);pszValue = temp16 & 0xFF;Carry = (temp16 >> 8) & 1
#define HL()   ((((WORD16)H) << 8)|L)
#define PCTR()  PC[PCIX]
static void __Reset8008(void) {
 for (A = 0;A < 8;A++) PC[A] = 0;
 A = B = C = D = E = H = L = pszValue = Halt = Carry = PCIX = 0;
 Cycles = 0;
}
static void __IsParityEven(void) {
 BYTE8 n = pszValue;
 BYTE8 bitCount = 0;
 while (n != 0) {
  if ((n & 1) != 0) bitCount++;
  n = n >> 1;
 }
 return ((n & 1) == 0);
}
#define JUMP() { PC[PCIX] = ((((WORD16)MB) << 8)|temp8) & 0x3FFF; }
#define CALL() { PCIX = (PCIX+1) & 7;JUMP(); }