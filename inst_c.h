// Generated from c.addi.yaml
#ifndef INST_DATA_H
#define INST_DATA_H

typedef struct {
    const char* name;
    const char* long_name;
    const char* description;
    const char* assembly;
    const char* match;
} instruction_t;

static const instruction_t instructions[] = {
    {"c.addi", "Add a sign-extended non-zero immediate", "C.ADDI adds the non-zero sign-extended 6-bit immediate to the value in register xd then writes the result to xd.\nC.ADDI expands into `addi xd, xd, imm`.\nC.ADDI is only valid when xd &ne; x0 and imm &ne; 0.\nThe code points with xd=x0 encode the C.NOP instruction; the remaining code points with imm=0 encode HINTs.\n", "xd, imm", "000-----------01"}
};

#define INSTRUCTION_COUNT 1
#endif // INST_DATA_H
