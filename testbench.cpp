#include <iostream>

using namespace std;

int main(){
	// We would like to show a rough idea how we would have done test bench
	//we would have put the test values into the binary and then checked with known answers if they were infact correct or not
	
	
	int32_t s[32]; // registers given binary
	int32_t imm; //immediate
	int32_t s_s[32]; // what the registers should be if correct
	int32_t dest; //destination register. we intended for this info to be taken from simulator
	int32_t lo,hi,pc,npc; // data from simulator
	int32_t lo_s,hi_s,pc_s,npc_s; // what it should be to be correct
	
	
	
	
	// Dummy variables to check if this would work. not sure how to link this with our simulator. Hence just called each instruction to 1. 
	
	int	ADD	=	0	;
	int	ADDI	=	0	;
	int	ADDIU	=	0	;
	int	ADDU	=	0	;
	int	AND	=	0	;
	int	ANDI	=	0	;
	int	BEQ	=	0	;
	int	BGEZ	=	0	;
	int	BGEZAL	=	0	;
	int	BGTZ	=	0	;
	int	BLEZ	=	0	;
	int	BLTZ	=	0	;
	int	BLTZAL	=	0	;
	int	BNE	=	0	;
	int	DIV	=	0	;
	int	DIVU	=	0	;
	int	J	=	0	;
	int	JALR	=	0	;
	int	JAL	=	0	;
	int	JR	=	0	;
	int	LB	=	0	;
	int	LBU	=	0	;
	int	LH	=	0	;
	int	LHU	=	0	;
	int	LUI	=	0	;
	int	LW	=	0	;
	int	LWL	=	0	;
	int	LWR	=	0	;
	int	MFHI	=	0	;
	int	MFLO	=	0	;
	int	MTHI	=	0	;
	int	MTLO	=	0	;
	int	MULT	=	0	;
	int	MULTU	=	0	;
	int	OR	=	0	;
	int	ORI	=	0	;
	int	SB	=	0	;
	int	SH	=	0	;
	int	SLL	=	0	;
	int	SLLV	=	0	;
	int	SLT	=	0	;
	int	SLTI	=	0	;
	int	SLTIU	=	0	;
	int	SLTU	=	0	;
	int	SRA	=	0	;
	int	SRAV	=	0	;
	int	SRL	=	0	;
	int	SRLV	=	0	;
	int	SUB	=	0	;
	int	SUBU	=	0	;
	int	SW	=	0	;
	int	XOR	=	0	;
	int	XORI	=	0	;
	
	//------------------------------------------------------------------------------
	
	// adding s[1] with s[2] and placing in s[3]
	s[1] = -50;
	s[2] = 1230;
	s_s[3] = 1230+50;
	
	if (s[3] == s_s[3]){
		ADD = 1;
	}
	
	if ( ADD == 1){
		cout << "0" << "," << " " << "ADD" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "0" << "," << " " << "ADD" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------
	
	//------------------------------------------------------------------------------
	
	s[1] = -50;
	imm = 80;
	s_s[3] = s[1]+imm; 
	
	if (s[3] == s_s[3]){
		ADDI = 1;
	}
	
	
	
	if ( ADDI == 1){
		cout << "1" << "," << " " << "ADDI" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "1" << "," << " " << "ADDI" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------
	
	//------------------------------------------------------------------------------
	
	
	s[1] = 50;
	imm = 80;
	s_s[3] = s[1]+imm; 
	
	if (s[3] == s_s[3]){
		ADDIU = 1;
	}

	if ( ADDIU == 1){
		cout << "2" << "," << " " << "ADDIU" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "2" << "," << " " << "ADDIU" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	// adding unsigned s[1] with s[2] and placing in s[3]
	s[1] = 50;
	s[2] = 1230;
	s_s[3] = 1230+50; 
	
	if (s[3] == s_s[3]){
		ADDU = 1;
	}
	
	
	if ( ADDU == 1){
		cout << "3" << "," << " " << "ADD" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "3" << "," << " " << "ADD" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------
	
	//------------------------------------------------------------------------------
	// adding s[1] with s[2] and placing in s[3]
	s[1] = 50;
	s[2] = 1230;
	s_s[3] = 1230 & 50;
	
	if (s[3] == s_s[3]){
		AND = 1;
	}
	
	
	if ( AND == 1){
		cout << "4" << "," << " " << "AND" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "4" << "," << " " << "AND" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	
	s[1] = 50;
	imm = 1230;
	s_s[3] = imm & 50;
	
	if (s[3] == s_s[3]){
		ANDI = 1;
	}
	

	
	if ( ANDI == 1){
		cout << "5" << "," << " " << "ANDI" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "5" << "," << " " << "ANDI" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( BEQ == 1){
		cout << "6" << "," << " " << "BEQ" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "6" << "," << " " << "BEQ" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( BGEZ == 1){
		cout << "7" << "," << " " << "BGEZ" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "7" << "," << " " << "BGEZ" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( BGEZAL == 1){
		cout << "8" << "," << " " << "BGEZAL" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "8" << "," << " " << "BGEZAL" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( BGTZ == 1){
		cout << "9" << "," << " " << "BGTZ" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "9" << "," << " " << "BGTZ" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( BLEZ == 1){
		cout << "10" << "," << " " << "BLEZ" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "10" << "," << " " << "BLEZ" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( BLTZ == 1){
		cout << "11" << "," << " " << "BLTZ" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "11" << "," << " " << "BLTZ" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( BLTZAL == 1){
		cout << "12" << "," << " " << "BLTZAL" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "12" << "," << " " << "BLTZAL" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( BNE == 1){
		cout << "13" << "," << " " << "BNE" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "13" << "," << " " << "BNE" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	s[1] = 1200;
	s[2] = -15;
	lo_s = s[1]/s[2];
	hi_s = s[1]%s[2];
	
	if (lo == lo_s && hi == hi_s){
		DIV = 1;
	}
	
	if ( DIV == 1){
		cout << "14" << "," << " " << "DIV" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "14" << "," << " " << "DIV" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	
	s[1] = 1200;
	s[2] = 15;
	lo_s = s[1]/s[2];
	hi_s = s[1]%s[2];
	
	if (lo == lo_s && hi == hi_s){
		DIVU = 1;
	}
	
	if ( DIVU == 1){
		cout << "15" << "," << " " << "DIVU" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "15" << "," << " " << "DIVU" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( J == 1){
		cout << "16" << "," << " " << "J" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "16" << "," << " " << "J" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	// your in register s[1] and you are jumping and linking to s[2]
	s[1] = 10;
	s[2] = 30;
	pc = 40;
	
	
	if ( pc == npc && npc == dest && s[31] == pc + 8){
		JALR = 1;
	}
	
	if ( JALR == 1){
		cout << "17" << "," << " " << "JALR" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "17" << "," << " " << "JALR" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( JAL == 1){
		cout << "18" << "," << " " << "JAL" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "18" << "," << " " << "JAL" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	// your in register s[1] and you are jumping to s[2]
	s[1] = 15;
	s[2] = 30;	
	pc = 64;
	
	if ( pc == npc && npc == s[2]){
		JR = 1;
	}

	
	if ( JR == 1){
		cout << "19" << "," << " " << "JR" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "19" << "," << " " << "JR" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( LB == 1){
		cout << "20" << "," << " " << "LB" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "20" << "," << " " << "LB" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( LBU == 1){
		cout << "21" << "," << " " << "LBU" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "21" << "," << " " << "LBU" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( LH == 1){
		cout << "22" << "," << " " << "LH" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "22" << "," << " " << "LH" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( LHU == 1){
		cout << "23" << "," << " " << "LHU" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "23" << "," << " " << "LHU" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( LUI == 1){
		cout << "24" << "," << " " << "LUI" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "24" << "," << " " << "LUI" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	if ( LW == 1){
		cout << "25" << "," << " " << "LW" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "25" << "," << " " << "LW" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( LWL == 1){
		cout << "26" << "," << " " << "LWL" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "26" << "," << " " << "LWL" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( LWR == 1){
		cout << "27" << "," << " " << "LWR" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "27" << "," << " " << "LWR" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	hi = 30;
	s[3] = 20;
	s_s[3] =30;
	
	if(s[3] == s_s[3]){
		MFHI = 1;
	}
	
	if ( MFHI == 1){
		cout << "28" << "," << " " << "MFHI" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "28" << "," << " " << "MFHI" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	lo = 30;
	s[3] = 20;
	s_s[3] =30;
	
	if(s[3] == s_s[3]){
		MFLO = 1;
	}
	
	
	if ( MFLO == 1){
		cout << "29" << "," << " " << "MFLO" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "29" << "," << " " << "MFLO" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( MTHI == 1){
		cout << "30" << "," << " " << "MTHI" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "30" << "," << " " << "MTHI" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( MTLO == 1){
		cout << "31" << "," << " " << "MTLO" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "31" << "," << " " << "MTLO" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( MULT == 1){
		cout << "32" << "," << " " << "MULT" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "32" << "," << " " << "MULT" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	if ( MULTU == 1){
		cout << "33" << "," << " " << "MULTU" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "33" << "," << " " << "MULTU" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	
	s[2] = 50;
	s[4] = 9;
	s_s[5] = 50|9;
	
	if (s[5] == s_s[5]){
		OR = 1;
	}
	
	if ( OR == 1){
		cout << "34" << "," << " " << "OR" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "34" << "," << " " << "OR" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( ORI == 1){
		cout << "35" << "," << " " << "ORI" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "35" << "," << " " << "ORI" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SB == 1){
		cout << "36" << "," << " " << "SB" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "36" << "," << " " << "SB" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SH == 1){
		cout << "37" << "," << " " << "SH" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "37" << "," << " " << "SH" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SLL == 1){
		cout << "38" << "," << " " << "SLL" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "38" << "," << " " << "SLL" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SLLV == 1){
		cout << "39" << "," << " " << "SLLV" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "39" << "," << " " << "SLLV" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SLT == 1){
		cout << "40" << "," << " " << "SLT" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "40" << "," << " " << "SLT" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SLTI == 1){
		cout << "41" << "," << " " << "SLTI" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "41" << "," << " " << "SLTI" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SLTIU == 1){
		cout << "42" << "," << " " << "SLTIU" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "42" << "," << " " << "SLTIU" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SLTU == 1){
		cout << "43" << "," << " " << "SLTU" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "43" << "," << " " << "SLTU" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SRA == 1){
		cout << "44" << "," << " " << "SRA" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "44" << "," << " " << "SRA" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SRAV == 1){
		cout << "45" << "," << " " << "SRAV" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "45" << "," << " " << "SRAV" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	if ( SRL == 1){
		cout << "46" << "," << " " << "SRL" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "46" << "," << " " << "SRL" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SRLV == 1){
		cout << "47" << "," << " " << "SRLV" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "47" << "," << " " << "SRLV" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	s[1] = 10;
	s[2] = -10;
	s_s[3] = s[1] - s [2];
	
	if (s[3] == s_s[3]){
		SUB = 1;
	}
	
	if ( SUB == 1){
		cout << "48" << "," << " " << "SUB" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "48" << "," << " " << "SUB" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	s[1] = 50;
	s[2] = 10;
	s_s[3] = s[1] - s [2];
	
	if (s[3] == s_s[3]){
		SUBU = 1;
	}	
	
	if ( SUBU == 1){
		cout << "49" << "," << " " << "SUBU" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "49" << "," << " " << "SUBU" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( SW == 1){
		cout << "50" << "," << " " << "SW" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "50" << "," << " " << "SW" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( XOR == 1){
		cout << "51" << "," << " " << "XOR" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "51" << "," << " " << "XOR" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------	//------------------------------------------------------------------------------
	if ( XORI == 1){
		cout << "52" << "," << " " << "XORI" << "," << " "<< "PASS" << "," << " " << 	"pk1815" << endl;
	}
	else{
		cout << "53" << "," << " " << "XORI" << "," << " "<< "FAIL" << "," << " " << 		"pk1815" << endl;
	}
	// -----------------------------------------------------------------------------
	
	

	
	
	
	
	
	return 0;
}