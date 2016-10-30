case 0x00: /**** hlt ****/
    if (phase == 1) {
        Halt = 1;
        DISPLAY(0,0,PCTR()-1,Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x01: /**** hlt ****/
    if (phase == 1) {
        Halt = 1;
        DISPLAY(0,0,PCTR()-1,Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x02: /**** rlc ****/
    if (phase == 1) {
        Carry = (A >> 7) & 1;
        A = ((A << 1) | Carry) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x03: /**** rnc ****/
    if (phase == 1) {
        if (!(Carry != 0)) PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x04: /**** adi $1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        ADD(MB,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x05: /**** rst 00 ****/
    if (phase == 1) {
        PCIX = (PCIX+1) & 7;
        PC[PCIX] = 0x00;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x06: /**** mvi a,$1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        A = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x07: /**** ret ****/
    if (phase == 1) {
        PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x08: /**** inr b ****/
    if (phase == 1) {
        pszValue = B = (B + 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x09: /**** dcr b ****/
    if (phase == 1) {
        pszValue = B = (B - 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x0a: /**** rrc ****/
    if (phase == 1) {
        Carry = A & 1;
        A = (A >> 1) | (Carry << 7);
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x0b: /**** rnz ****/
    if (phase == 1) {
        if (!(pszValue == 0)) PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x0c: /**** aci $1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        ADD(MB,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x0d: /**** rst 08 ****/
    if (phase == 1) {
        PCIX = (PCIX+1) & 7;
        PC[PCIX] = 0x08;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x0e: /**** mvi b,$1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        B = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x0f: /**** ret ****/
    if (phase == 1) {
        PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x10: /**** inr c ****/
    if (phase == 1) {
        pszValue = C = (C + 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x11: /**** dcr c ****/
    if (phase == 1) {
        pszValue = C = (C - 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x12: /**** ral ****/
    if (phase == 1) {
        temp16 = (A << 1) | Carry;
        A = temp16 & 0xFF;
        Carry = temp16 >> 8;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x13: /**** rp ****/
    if (phase == 1) {
        if (!((pszValue & 0x80) != 0)) PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x14: /**** sui $1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        SUB(MB,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x15: /**** rst 10 ****/
    if (phase == 1) {
        PCIX = (PCIX+1) & 7;
        PC[PCIX] = 0x10;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x16: /**** mvi c,$1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        C = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x17: /**** ret ****/
    if (phase == 1) {
        PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x18: /**** inr d ****/
    if (phase == 1) {
        pszValue = D = (D + 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x19: /**** dcr d ****/
    if (phase == 1) {
        pszValue = D = (D - 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x1a: /**** rar ****/
    if (phase == 1) {
        temp16 = A | (Carry << 8);
        A = (temp16 >> 1) & 0xFF;
        Carry = temp16 & 1;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x1b: /**** rpo ****/
    if (phase == 1) {
        if (!(__IsParityEven())) PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x1c: /**** sbi $1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        SUB(MB,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x1d: /**** rst 18 ****/
    if (phase == 1) {
        PCIX = (PCIX+1) & 7;
        PC[PCIX] = 0x18;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x1e: /**** mvi d,$1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        D = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x1f: /**** ret ****/
    if (phase == 1) {
        PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x20: /**** inr e ****/
    if (phase == 1) {
        pszValue = E = (E + 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x21: /**** dcr e ****/
    if (phase == 1) {
        pszValue = E = (E - 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x23: /**** rc ****/
    if (phase == 1) {
        if (Carry != 0) PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x24: /**** ani $1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        Carry = 0;
        A = pszValue = A & MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x25: /**** rst 20 ****/
    if (phase == 1) {
        PCIX = (PCIX+1) & 7;
        PC[PCIX] = 0x20;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x26: /**** mvi e,$1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        E = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x27: /**** ret ****/
    if (phase == 1) {
        PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x28: /**** inr h ****/
    if (phase == 1) {
        pszValue = H = (H + 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x29: /**** dcr h ****/
    if (phase == 1) {
        pszValue = H = (H - 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x2b: /**** rz ****/
    if (phase == 1) {
        if (pszValue == 0) PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x2c: /**** xri $1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        Carry = 0;
        A = pszValue = A ^ MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x2d: /**** rst 28 ****/
    if (phase == 1) {
        PCIX = (PCIX+1) & 7;
        PC[PCIX] = 0x28;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x2e: /**** mvi h,$1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        H = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x2f: /**** ret ****/
    if (phase == 1) {
        PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x30: /**** inr l ****/
    if (phase == 1) {
        pszValue = L = (L + 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x31: /**** dcr l ****/
    if (phase == 1) {
        pszValue = L = (L - 1) & 0xFF;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x33: /**** rm ****/
    if (phase == 1) {
        if ((pszValue & 0x80) != 0) PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x34: /**** ori $1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        Carry = 0;
        A = pszValue = A | MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x35: /**** rst 30 ****/
    if (phase == 1) {
        PCIX = (PCIX+1) & 7;
        PC[PCIX] = 0x30;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x36: /**** mvi l,$1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        L = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x37: /**** ret ****/
    if (phase == 1) {
        PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x3b: /**** rpe ****/
    if (phase == 1) {
        if (__IsParityEven()) PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

case 0x3c: /**** cpi $1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        SUB(MB,0);
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x3d: /**** rst 38 ****/
    if (phase == 1) {
        PCIX = (PCIX+1) & 7;
        PC[PCIX] = 0x38;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x3e: /**** mvi m,$1 ****/
    if (phase == 1) {
        FETCH();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 9;
        phase = 2;
    }
    else if (phase == 2) {
        MA = HL();
        DISPLAY(1,1,MA,MB);
        phase = 3;
    }
    else if (phase == 3) {
        WRITE();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x3f: /**** ret ****/
    if (phase == 1) {
        PCIX = (PCIX-1) & 7;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x40: /**** jnc $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (!(Carry != 0)) JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x41: /**** in 00 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x00<< 8),Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        A = INPORT00(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x42: /**** cnc $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (!(Carry != 0)) CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x43: /**** in 01 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x01<< 8),Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        A = INPORT01(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x44: /**** jmp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x45: /**** in 02 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x02<< 8),Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        A = INPORT02(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x46: /**** call $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x47: /**** in 03 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x03<< 8),Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        A = INPORT03(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x48: /**** jnz $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (!(pszValue == 0)) JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x49: /**** in 04 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x04<< 8),Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        A = INPORT04(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x4a: /**** cnz $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (!(pszValue == 0)) CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x4b: /**** in 05 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x05<< 8),Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        A = INPORT05(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x4c: /**** jmp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x4d: /**** in 06 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x06<< 8),Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        A = INPORT06(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x4e: /**** call $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x4f: /**** in 07 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x07<< 8),Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        A = INPORT07(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x50: /**** jp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (!((pszValue & 0x80) != 0)) JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x51: /**** out 08 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x08<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT08(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x52: /**** cp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (!((pszValue & 0x80) != 0)) CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x53: /**** out 09 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x09<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT09(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x54: /**** jmp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x55: /**** out 0a ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x0A<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT0A(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x56: /**** call $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x57: /**** out 0b ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x0B<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT0B(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x58: /**** jpo $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (!(__IsParityEven())) JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x59: /**** out 0c ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x0C<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT0C(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x5a: /**** cpo $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (!(__IsParityEven())) CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x5b: /**** out 0d ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x0D<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT0D(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x5c: /**** jmp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x5d: /**** out 0e ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x0E<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT0E(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x5e: /**** call $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x5f: /**** out 0f ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x0F<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT0F(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x60: /**** jc $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (Carry != 0) JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x61: /**** out 10 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x10<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT10(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x62: /**** cc $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (Carry != 0) CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x63: /**** out 11 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x11<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT11(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x64: /**** jmp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x65: /**** out 12 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x12<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT12(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x66: /**** call $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x67: /**** out 13 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x13<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT13(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x68: /**** jz $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (pszValue == 0) JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x69: /**** out 14 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x14<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT14(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x6a: /**** cz $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (pszValue == 0) CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x6b: /**** out 15 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x15<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT15(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x6c: /**** jmp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x6d: /**** out 16 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x16<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT16(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x6e: /**** call $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x6f: /**** out 17 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x17<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT17(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x70: /**** jm $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if ((pszValue & 0x80) != 0) JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x71: /**** out 18 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x18<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT18(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x72: /**** cm $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if ((pszValue & 0x80) != 0) CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x73: /**** out 19 ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x19<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT19(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x74: /**** jmp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x75: /**** out 1a ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x1A<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT1A(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x76: /**** call $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x77: /**** out 1b ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x1B<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT1B(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x78: /**** jpe $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (__IsParityEven()) JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x79: /**** out 1c ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x1C<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT1C(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x7a: /**** cpe $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 10;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        if (__IsParityEven()) CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x7b: /**** out 1d ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x1D<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT1D(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x7c: /**** jmp $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        JUMP();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x7d: /**** out 1e ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x1E<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT1E(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x7e: /**** call $2 ****/
    if (phase == 1) {
        FETCH();
        temp8 = MB;
        DISPLAY(1,0,PCTR(),Opcode);
        Cycles += 11;
        phase = 2;
    }
    else if (phase == 2) {
        FETCH();
        DISPLAY(1,0,PCTR(),temp8);
        phase = 3;
    }
    else if (phase == 3) {
        CALL();
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x7f: /**** out 1f ****/
    if (phase == 1) {
        DISPLAY(0,1,A|(0x1F<< 8),Opcode);
        Cycles += 6;
        phase = 2;
    }
    else if (phase == 2) {
        OUTPORT1F(A);
        DISPLAY(0,0,PCTR(),Opcode);
        phase = 0;
    }
    break;

case 0x80: /**** add a ****/
    if (phase == 1) {
        ADD(A,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x81: /**** add b ****/
    if (phase == 1) {
        ADD(B,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x82: /**** add c ****/
    if (phase == 1) {
        ADD(C,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x83: /**** add d ****/
    if (phase == 1) {
        ADD(D,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x84: /**** add e ****/
    if (phase == 1) {
        ADD(E,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x85: /**** add h ****/
    if (phase == 1) {
        ADD(H,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x86: /**** add l ****/
    if (phase == 1) {
        ADD(L,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x87: /**** add m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,HL,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        ADD(MB,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x88: /**** adc a ****/
    if (phase == 1) {
        ADD(A,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x89: /**** adc b ****/
    if (phase == 1) {
        ADD(B,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x8a: /**** adc c ****/
    if (phase == 1) {
        ADD(C,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x8b: /**** adc d ****/
    if (phase == 1) {
        ADD(D,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x8c: /**** adc e ****/
    if (phase == 1) {
        ADD(E,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x8d: /**** adc h ****/
    if (phase == 1) {
        ADD(H,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x8e: /**** adc l ****/
    if (phase == 1) {
        ADD(L,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x8f: /**** adc m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,HL,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        ADD(MB,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x90: /**** sub a ****/
    if (phase == 1) {
        SUB(A,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x91: /**** sub b ****/
    if (phase == 1) {
        SUB(B,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x92: /**** sub c ****/
    if (phase == 1) {
        SUB(C,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x93: /**** sub d ****/
    if (phase == 1) {
        SUB(D,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x94: /**** sub e ****/
    if (phase == 1) {
        SUB(E,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x95: /**** sub h ****/
    if (phase == 1) {
        SUB(H,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x96: /**** sub l ****/
    if (phase == 1) {
        SUB(L,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x97: /**** sub m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,HL,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        SUB(MB,0);
        A = pszValue;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0x98: /**** sbb a ****/
    if (phase == 1) {
        SUB(A,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x99: /**** sbb b ****/
    if (phase == 1) {
        SUB(B,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x9a: /**** sbb c ****/
    if (phase == 1) {
        SUB(C,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x9b: /**** sbb d ****/
    if (phase == 1) {
        SUB(D,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x9c: /**** sbb e ****/
    if (phase == 1) {
        SUB(E,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x9d: /**** sbb h ****/
    if (phase == 1) {
        SUB(H,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x9e: /**** sbb l ****/
    if (phase == 1) {
        SUB(L,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0x9f: /**** sbb m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,HL,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        SUB(MB,Carry);
        A = pszValue;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xa0: /**** ana a ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A & A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xa1: /**** ana b ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A & B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xa2: /**** ana c ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A & C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xa3: /**** ana d ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A & D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xa4: /**** ana e ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A & E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xa5: /**** ana h ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A & H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xa6: /**** ana l ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A & L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xa7: /**** ana m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,HL,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        Carry = 0;
        A = pszValue = A & MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xa8: /**** xra a ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A ^ A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xa9: /**** xra b ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A ^ B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xaa: /**** xra c ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A ^ C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xab: /**** xra d ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A ^ D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xac: /**** xra e ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A ^ E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xad: /**** xra h ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A ^ H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xae: /**** xra l ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A ^ L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xaf: /**** xra m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,HL,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        Carry = 0;
        A = pszValue = A ^ MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xb0: /**** ora a ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A | A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xb1: /**** ora b ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A | B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xb2: /**** ora c ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A | C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xb3: /**** ora d ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A | D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xb4: /**** ora e ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A | E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xb5: /**** ora h ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A | H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xb6: /**** ora l ****/
    if (phase == 1) {
        Carry = 0;
        A = pszValue = A | L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xb7: /**** ana m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,HL,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        Carry = 0;
        A = pszValue = A | MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xb8: /**** cmp a ****/
    if (phase == 1) {
        SUB(A,0);
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xb9: /**** cmp b ****/
    if (phase == 1) {
        SUB(B,0);
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xba: /**** cmp c ****/
    if (phase == 1) {
        SUB(C,0);
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xbb: /**** cmp d ****/
    if (phase == 1) {
        SUB(D,0);
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xbc: /**** cmp e ****/
    if (phase == 1) {
        SUB(E,0);
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xbd: /**** cmp h ****/
    if (phase == 1) {
        SUB(H,0);
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xbe: /**** cmp l ****/
    if (phase == 1) {
        SUB(L,0);
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xbf: /**** cmp m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,HL,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        SUB(MB,0);
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xc0: /**** mov a,a ****/
    if (phase == 1) {
        A = A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xc1: /**** mov a,b ****/
    if (phase == 1) {
        A = B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xc2: /**** mov a,c ****/
    if (phase == 1) {
        A = C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xc3: /**** mov a,d ****/
    if (phase == 1) {
        A = D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xc4: /**** mov a,e ****/
    if (phase == 1) {
        A = E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xc5: /**** mov a,h ****/
    if (phase == 1) {
        A = H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xc6: /**** mov a,l ****/
    if (phase == 1) {
        A = L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xc7: /**** mov a,m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        A = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xc8: /**** mov b,a ****/
    if (phase == 1) {
        B = A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xc9: /**** mov b,b ****/
    if (phase == 1) {
        B = B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xca: /**** mov b,c ****/
    if (phase == 1) {
        B = C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xcb: /**** mov b,d ****/
    if (phase == 1) {
        B = D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xcc: /**** mov b,e ****/
    if (phase == 1) {
        B = E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xcd: /**** mov b,h ****/
    if (phase == 1) {
        B = H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xce: /**** mov b,l ****/
    if (phase == 1) {
        B = L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xcf: /**** mov b,m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        B = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xd0: /**** mov c,a ****/
    if (phase == 1) {
        C = A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xd1: /**** mov c,b ****/
    if (phase == 1) {
        C = B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xd2: /**** mov c,c ****/
    if (phase == 1) {
        C = C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xd3: /**** mov c,d ****/
    if (phase == 1) {
        C = D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xd4: /**** mov c,e ****/
    if (phase == 1) {
        C = E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xd5: /**** mov c,h ****/
    if (phase == 1) {
        C = H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xd6: /**** mov c,l ****/
    if (phase == 1) {
        C = L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xd7: /**** mov c,m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        C = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xd8: /**** mov d,a ****/
    if (phase == 1) {
        D = A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xd9: /**** mov d,b ****/
    if (phase == 1) {
        D = B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xda: /**** mov d,c ****/
    if (phase == 1) {
        D = C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xdb: /**** mov d,d ****/
    if (phase == 1) {
        D = D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xdc: /**** mov d,e ****/
    if (phase == 1) {
        D = E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xdd: /**** mov d,h ****/
    if (phase == 1) {
        D = H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xde: /**** mov d,l ****/
    if (phase == 1) {
        D = L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xdf: /**** mov d,m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        D = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xe0: /**** mov e,a ****/
    if (phase == 1) {
        E = A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xe1: /**** mov e,b ****/
    if (phase == 1) {
        E = B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xe2: /**** mov e,c ****/
    if (phase == 1) {
        E = C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xe3: /**** mov e,d ****/
    if (phase == 1) {
        E = D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xe4: /**** mov e,e ****/
    if (phase == 1) {
        E = E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xe5: /**** mov e,h ****/
    if (phase == 1) {
        E = H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xe6: /**** mov e,l ****/
    if (phase == 1) {
        E = L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xe7: /**** mov e,m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        E = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xe8: /**** mov h,a ****/
    if (phase == 1) {
        H = A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xe9: /**** mov h,b ****/
    if (phase == 1) {
        H = B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xea: /**** mov h,c ****/
    if (phase == 1) {
        H = C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xeb: /**** mov h,d ****/
    if (phase == 1) {
        H = D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xec: /**** mov h,e ****/
    if (phase == 1) {
        H = E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xed: /**** mov h,h ****/
    if (phase == 1) {
        H = H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xee: /**** mov h,l ****/
    if (phase == 1) {
        H = L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xef: /**** mov h,m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        H = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xf0: /**** mov l,a ****/
    if (phase == 1) {
        L = A;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xf1: /**** mov l,b ****/
    if (phase == 1) {
        L = B;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xf2: /**** mov l,c ****/
    if (phase == 1) {
        L = C;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xf3: /**** mov l,d ****/
    if (phase == 1) {
        L = D;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xf4: /**** mov l,e ****/
    if (phase == 1) {
        L = E;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xf5: /**** mov l,h ****/
    if (phase == 1) {
        L = H;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xf6: /**** mov l,l ****/
    if (phase == 1) {
        L = L;
        DISPLAY(0,0,PCTR(),Opcode);
        Cycles += 5;
        phase = 0;
    }
    break;

case 0xf7: /**** mov l,m ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,0,MA,Opcode);
        Cycles += 8;
        phase = 2;
    }
    else if (phase == 2) {
        READ();
        L = MB;
        DISPLAY(0,0,PCTR(),MB);
        phase = 0;
    }
    break;

case 0xf8: /**** mov m,a ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,1,MA,Opcode);
        Cycles += 7;
        phase = 2;
    }
    else if (phase == 2) {
        MB = A;
        WRITE();
        DISPLAY(0,0,PCTR(),A);
        phase = 0;
    }
    break;

case 0xf9: /**** mov m,b ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,1,MA,Opcode);
        Cycles += 7;
        phase = 2;
    }
    else if (phase == 2) {
        MB = B;
        WRITE();
        DISPLAY(0,0,PCTR(),B);
        phase = 0;
    }
    break;

case 0xfa: /**** mov m,c ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,1,MA,Opcode);
        Cycles += 7;
        phase = 2;
    }
    else if (phase == 2) {
        MB = C;
        WRITE();
        DISPLAY(0,0,PCTR(),C);
        phase = 0;
    }
    break;

case 0xfb: /**** mov m,d ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,1,MA,Opcode);
        Cycles += 7;
        phase = 2;
    }
    else if (phase == 2) {
        MB = D;
        WRITE();
        DISPLAY(0,0,PCTR(),D);
        phase = 0;
    }
    break;

case 0xfc: /**** mov m,e ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,1,MA,Opcode);
        Cycles += 7;
        phase = 2;
    }
    else if (phase == 2) {
        MB = E;
        WRITE();
        DISPLAY(0,0,PCTR(),E);
        phase = 0;
    }
    break;

case 0xfd: /**** mov m,h ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,1,MA,Opcode);
        Cycles += 7;
        phase = 2;
    }
    else if (phase == 2) {
        MB = H;
        WRITE();
        DISPLAY(0,0,PCTR(),H);
        phase = 0;
    }
    break;

case 0xfe: /**** mov m,l ****/
    if (phase == 1) {
        MA = HL();
        DISPLAY(1,1,MA,Opcode);
        Cycles += 7;
        phase = 2;
    }
    else if (phase == 2) {
        MB = L;
        WRITE();
        DISPLAY(0,0,PCTR(),L);
        phase = 0;
    }
    break;

case 0xff: /**** hlt ****/
    if (phase == 1) {
        Halt = 1;
        DISPLAY(0,0,PCTR()-1,Opcode);
        Cycles += 4;
        phase = 0;
    }
    break;

