#ifndef _VF_DES_H_
#define _VF_DES_H_

typedef enum
{
    SINGLE_DES = 0,
    TRIPLE_DES,
    SM4_ALG,
} Alg_Type;

/* ???? */
void des(byte *dkey, byte *tt, byte *cipher, char f);
void TripleDes(byte *dkey, byte *tt, byte *cipher, char f);

#endif
