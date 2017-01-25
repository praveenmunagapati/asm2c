// Generated by asm2c https://github.com/frranck/asm2c

#include "lodsb.h"
Memory m = {
{2,5,6}, //var1
{4,6,9}, //var2
{11,((0-11)),2,4}, //var3
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //var4
{97,98,99,100}, //var5
{0}, //dummy1
0,0,0,0,0,0,0,0,0,0,0,0,0,0, // registers
0,0,0,0,0,0, //flags
0, //exitCode
{0}, //vgaPalette
0,{0},1,{0},0,{0},{0},{0},{0}, NULL};

int program() {
jmp_buf jmpbuffer;
void * dest;
void * src;
#ifdef TEST
dest=NULL;src=NULL; //to avoid a warning.
#endif
if (m.executionFinished) goto moveToBackGround;
if (m.jumpToBackGround) {
m.jumpToBackGround = 0;
RET;
}
R(PUSH(16,(READDW(ds))));
R(POP(16,(READDW(es))));
R(MOV(32,m.esi,32,(((dd)offsetof(struct Mem,var1)))));
R(MOV(32,m.edi,32,(((dd)offsetof(struct Mem,var4)))));
R(MOV(32,READDD(eax),32,(dd)4294967295));
R(LODSB);
R(CMP(8,READDBl(eax),8,(db)2));
R(JNE(failure));
R(CMP(8,READDBh(eax),8,(db)255));
R(JNE(failure));
R(CMP(8,READDBh(eax),8,(db)((0-1))));
R(JNE(failure));
R(MOV(32,READDD(ecx),32,(dd)(is_little_endian()?1684234849:1633837924)));
R(XOR(32,READDD(eax),32,(dd)READDD(eax)));
R(LEA(32,m.esi,32,(((dd)offsetof(struct Mem,var5)))));
R(LODSD);
R(MOV(32,READDD(ebx),32,(dd)READDD(eax)));
R(CMP(32,READDD(ebx),32,(dd)(is_little_endian()?1684234849:1633837924)));
R(JNE(failure));
R(MOV(8,READDBl(eax),8,(db)0));
R(JMP(exitlabel));
failure:
R(MOV(8,READDBl(eax),8,(db)1));
exitlabel:
R(MOV(8,READDBh(eax),8,(db)76));
R(INT(33));

m.executionFinished = 1;
moveToBackGround:
return (m.executionFinished == 0);
}

void stackDump() {
    printf("is_little_endian()=%d\n",is_little_endian());
    printf("sizeof(dd)=%zu\n",sizeof(dd));
    printf("sizeof(dd *)=%zu\n",sizeof(dd *));
    printf("sizeof(dw)=%zu\n",sizeof(dw));
    printf("sizeof(db)=%zu\n",sizeof(db));
    printf("sizeof(mem)=%zu\n",sizeof(m));
 //   printf("sizeof(mem)=%zu\n", offsetof(struct Mem,heapPointer)-offsetof(struct Mem,winhdle));
//    printf("sizeof(dataSeg)=%x\n", (dd) (offsetof(struct Mem,enddata)-offsetof(struct Mem,beginningdata)));
    printf("eax: %x\n",m.eax);
    hexDump(&m.eax,sizeof(dd));
    printf("ebx: %x\n",m.ebx);
    printf("ecx: %x\n",m.ecx);
    printf("edx: %x\n",m.edx);
    printf("ebp: %x\n",m.ebp);
    printf("cs: %d -> %p\n",m.cs,(void *) realAddress(0,cs));
    printf("ds: %d -> %p\n",m.ds,(void *) realAddress(0,ds));
    printf("esi: %x\n",m.esi);
    printf("ds:esi %p\n",(void *) realAddress(m.esi,ds));
    printf("es: %d -> %p\n",m.es,(void *) realAddress(0,es));
    hexDump(&m.es,sizeof(dd));
    printf("edi: %x\n",m.edi);
    printf("es:edi %p\n",(void *) realAddress(m.edi,es));
    hexDump((void *) realAddress(m.edi,es),50);
    printf("fs: %d -> %p\n",m.fs,(void *) realAddress(0,fs));
    printf("gs: %d -> %p\n",m.gs,(void *) realAddress(0,gs));
    printf("adress heap: %p\n",(void *) &m.heap);
    printf("adress vgaRam: %p\n",(void *) &m.vgaRam);
    printf("first pixels vgaRam: %x\n",*m.vgaRam);
    printf("flags: ZF = %d\n",m.ZF);
    printf("top stack=%d\n",m.stackPointer);
}

// thanks to paxdiablo http://stackoverflow.com/users/14860/paxdiablo for the hexDump function
void hexDump (void *addr, int len) {
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;

    printf ("hexDump %p:\n", addr);
    
    if (len == 0) {
        printf("  ZERO LENGTH\n");
        return;
    }
    if (len < 0) {
        printf("  NEGATIVE LENGTH: %i\n",len);
        return;
    }
    
    // Process every byte in the data.
    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).
        
        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.
            if (i != 0)
                printf ("  %s\n", buff);
            
            // Output the offset.
            printf ("  %04x ", i);
        }
        
        // Now the hex code for the specific character.
        printf (" %02x", pc[i]);
        
        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }
    
    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }

    // And print the final ASCII bit.
    printf ("  %s\n", buff);
}

void asm2C_OUT(int16_t address, int data) {
    static int indexPalette = 0;
    switch(address) {
        case 0x3c8:
            indexPalette=data;
            //printf("reset indexPalette to %d\n",indexPalette);
            break;
        case 0x3c9:
            if (indexPalette<768) {
               // printf("m.vgaPalette %d -> %d\n",indexPalette,data);
                m.vgaPalette[indexPalette]=data;
                indexPalette++;
            } else {
                printf("Error: indexPalette>767 %d\n",indexPalette);
            }
            break;
        default:
            printf("unknown OUT %d,%d\n",address, data);
    }
}

int8_t asm2C_IN(int16_t address) {
    static _Bool vblTick = 1;
    switch(address) {
        case 0x3DA:
            if (vblTick) {
                vblTick = 0;
                return 0;
            } else {
                vblTick = 1;
                m.jumpToBackGround = 1;
                return 8;
            }
            break;
        default:
            printf("Unknown IN %d\n",address);
            return 0;
    }
}

void asm2C_INT(int a) {
    static FILE * file;
    db ah=READDBh(eax);
    db al=READDBl(eax);
    dw ax=READDW(eax);
    dw bx=READDW(ebx);
    dw cx=READDW(ecx);
    dw dx=READDW(edx);
    m.CF = 0;
    switch(a) {
        case 0x10:
        {
            switch(ax)
            {
                case 0x03: {
                    printf("Switch to text mode\n");
                    return;
                }
                case 0x13: {
                    printf("Switch to VGA\n");
                    return;
                }
            }
            break;
        }
        case 0x21:
            switch(ah)
        {
            case 0x9:
            {
                char * s=(char *) realAddress(m.edx,ds);
                for (int i=0;s[i]!='$';i++) {
                    printf("%c", s[i]);
                }
                return;
            }
            case 0x2c:
            {
                //MOV(8,8,READDBh(edx),(db)2);
                // TOFIX
                m.edx=0x200;
                return;
            }
            case 0x3d:
            {
                char fileName[1000];
                if (m.path!=NULL) {
                    sprintf(fileName,"%s/%s",m.path,(const char *) realAddress(m.edx, ds));
                } else {
                    sprintf(fileName,"%s",(const char *) realAddress(m.edx, ds));
                }
                file=fopen(fileName, "rb"); //TOFIX, multiple files support
                printf("Opening file %s -> %p\n",fileName,(void *) file);
                if (file!=NULL) {
                    m.eax=1; //TOFIX
                } else {
                    m.CF = 1;
                    printf("Error opening file %s\n",fileName);
                }
                /*
                // [Index]AH = 3Dh - "OPEN" - OPEN EXISTING FILE
            Entry:

                AL = access and sharing modes
            DS:DX -> ASCIZ filename
            Return:

                CF clear if successful, AX = file handle
                    CF set on error AX = error code (01h,02h,03h,04h,05h,0Ch,56h)
                    */
                // TODO
                return;
            }
            case 0x3e:
            {
              // bx: file handle to close
              //TOFIX
              printf("Closing file. bx:%d\n",bx);
              if (fclose(file))  {
                    m.CF = 1;
                      perror("Error");
                      printf("Error closing file ? bx:%d %p\n",bx,(void *) file);
                }

                file=NULL;
              return;
            }
            case 0x3f:
            {
                /*
                [Index]AH = 3Fh - "READ" - READ FROM FILE OR DEVICE

            Entry:

                BX = file handle
                CX = number of bytes to read
            DS:DX -> buffer for data
                Return:

                CF clear if successful - AX = number of bytes actually read (0 if at EOF before call)
                    CF set on error AX = error code (05h,06h)
                    */
                //char grosbuff[100000];
                void * buffer=(db *) realAddress(m.edx, ds);
                //buffer=grosbuff;
                printf("Reading ecx=%d cx=%d eds=%x edx=%x -> %p file: %p\n",m.ecx,cx,m.ds,m.edx,buffer,(void *)  file);

                if (feof(file)) {
                    printf("feof(file)\n");
                  m.eax=0;
                } else {
                    size_t r=fread (buffer,1,cx,file);

//                  size_t r=fread (buffer,1,cx,file);
                  if (r!=cx) {
                      perror("Error");
                      printf("r!=cx cx:%d R:%zu \n",cx,r);
                    if(!feof(file)) {
                      printf("Error reading ? %d %zu %p\n",cx,r,(void *) file);
                      m.CF = 1;
                    }
                  } else {
                      printf("Reading OK %p\n",(void *) file);
                  }
                  m.eax=r;
                }
                /*
                if (ax!=cx) {
                    printf("Error reading ? %d %d\n",ax,cx);
                    m.CF = 1;

                }
                 */
                return;
            }
                // [Index]AH=42h - "LSEEK" - SET CURRENT FILE POSITION
            case 0x42:
            {
                /*

                 AH=42h - "LSEEK" - SET CURRENT FILE POSITION

                 Entry:

                 AL = origin of move 00h start of file 01h current file position 02h end of file
                 BX = file handle
                 CX:DX = offset from origin of new file position

                 */
                int seek = 0;
                switch(ah) {
                    case 0x0:
                        seek = SEEK_SET;
                        break;
                    case 0x1:
                        seek = SEEK_CUR;
                        break;
                    case 0x2:
                        seek = SEEK_END;
                        break;
                }
                long int offset=(cx<<16)+dx;
                printf("Seeking to offset %ld %d\n",offset,seek);
                if (fseek(file,offset,seek)!=0) {
                    printf("Error seeking\n");
                }
                return;
            }

            case 0x4c:
            {
                stackDump();
                m.jumpToBackGround = 1;
                m.executionFinished = 1;
                m.exitCode = al;
                return;
            }
            default:
                break;
        }
        case 0x31:
            switch(ax)
        {
            case 0x0:
            {
                /*
                ;2.0 - Function 0000h - Allocate Descriptors:
                ;--------------------------------------------
                ;  Allocates one or more descriptors in the client's descriptor table. The
                ;descriptor(s) allocated must be initialized by the application with other
                ;function calls.
                ;In:
                ;  AX     = 0000h
                ;  CX     = number of descriptors to allocate
                ;Out:
                ;  if successful:
                ;    carry flag clear
                ;    AX     = base selector
                 */
                printf("Function 0000h - Allocate %d Descriptors\n",cx);
                if (m.selectorsPointer+cx>=NB_SELECTORS) {
                    m.CF = 1;
                    printf("Not enough free selectors (increase NB_SELECTORS)\n");
                    return;
                } else {
                    m.eax = m.selectorsPointer;
                    m.selectorsPointer+=cx;
                    printf("Return %x\n",m.eax);
                }
                return;
            }
            case 0x02:
            {
                /*
                This function Converts a real mode segment into a protected mode descriptor.
                 BX =    real mode segment
                 Out:
                 if successful:
                 carry flag clear
                 AX =  selector
                 if failed:
                 carry flag set
                */
                printf("Function 0002h - Converts a real mode segment into a protected mode descriptor real mode segment: %d\n",m.ebx);
                if (m.selectorsPointer+1>=NB_SELECTORS) {
                    m.CF = 1;
                    printf("Not enough free selectors (increase NB_SELECTORS)\n");
                    return;
                }
                // TOFIX ?
                // always return vga adress.
                m.selectors[m.selectorsPointer]=offsetof(struct Mem,vgaRam); // bx;
                m.eax=m.selectorsPointer;
                printf("Returns new selector: eax: %d\n",m.eax);
                m.selectorsPointer++;

                // Multiple calls for the same real mode segment return the same selector. The returned descriptor should never be modified or freed. <- TOFIX
                return;
            }
                /*
                ;2.5 - Function 0007h - Set Segment Base Address:
                ; Sets the 32bit linear base address field in the descriptor for the specified
                ; segment.
                ; In:   AX     = 0007h
                ; BX     = selector
                ;  CX:DX  = 32bit linear base address of segment
                */
            case 0x07:
            {
                printf("Function 0007h - Set Segment Base Address: ebx: %x, edx:%x ecx:%x\n",m.ebx,m.edx,m.ecx);
                if (bx>m.selectorsPointer) {
                    m.CF = 1;
                    printf("Error: selector number doesnt exist\n");
                    return;
                }
                m.selectors[bx]=(READDW(edx)&0xffff)+(READDW(ecx)<<16);
                printf("Address for selector %d: %x\n",bx,m.selectors[bx]);
                return;
            }
            case 0x08:
            {
                /*
                ;2.6 - Function 0008h - Set Segment Limit:
                ;-----------------------------------------
                ;  Sets the limit field in the descriptor for the specified segment.
                ;  In:
                ;  AX     = 0008h
                ;  BX     = selector
                ;  CX:DX  = 32bit segment limit
                ;  Out:
                ;  if successful:
                ;    carry flag clear
                ;  if failed:
                ;    carry flag set
                 */

                // To implement...
                printf("Function 0008h - Set Segment Limit for selector %d (Ignored)\n",bx);
                return;
            }
            case 0x501:
            {
                /*
                ;2.29 - Function 0501h - Allocate Memory Block:
                ;In:  AX     = 0501h
                ;  BX:CX  = size of block in bytes (must be non-zero)
                ;Out: if successful:
                ;    carry flag clear
                ;    BX:CX  = linear address of allocated memory block
                ;    SI:DI  = memory block handle (used to resize and free block)
                */
                int32_t nbBlocks=(bx<<16)+cx;
                printf("Function 0501h - Allocate Memory Block: %d bytes\n",nbBlocks);

                if (m.heapPointer+nbBlocks>=HEAP_SIZE) {
                    m.CF = 1;
                    printf("Not enough memory (increase HEAP_SIZE)\n");
                    return;
                } else {
                    dd a=offsetof(struct Mem,heap)+m.heapPointer;
                    m.heapPointer+=nbBlocks;
                    {
                        dd n=offsetof(struct Mem,heap)+m.heapPointer;
                        printf("New top of heap: %x\n",n);
                    }
                    m.ecx=a & 0xFFFF;
                    m.ebx=a >> 16;
                    m.edi=0; // TOFIX
                    m.esi=0; // TOFIX
                    printf("Return %x ebx:ecx %x:%x\n",a,m.ebx,m.ecx);
                    return;
                }
                break;
            }
            case 0x205:{
                /*
                 fo implement
                 ;2.18 - Function 0204h - Get Protected Mode Interrupt Vector:
                 ;------------------------------------------------------------
                 ;
                 ;  Returns the address of the current protected mode interrupt handler for the
                 ;specified interrupt.
                 ;
                 ;In:
                 ;  AX     = 0204h
                 ;  BL     = interrupt number
                 ;
                 ;Out:
                 ;  always successful:
                 ;    carry flag clear
                 ;    CX:EDX = selector:offset of protected mode interrupt handler

                 ;  AX     = 0204h
                 ;  BL     = interrupt number
                 ;
                 ;Out:
                 ;  always successful:
                 ;    carry flag clear
                 ;    CX:EDX = selector:offset of protected mode interrupt handler
                 */

                return;
            }
            default:
                break;
        }
            break;

        default:
            break;
    }
    m.CF = 1;
    printf("Error DOSInt 0x%x ah:0x%x al:0x%x: not supported.\n",a,ah,al);
}

#ifdef INCLUDEMAIN
int main() {
stackDump();while (program()) { }
return m.exitCode;
}
#endif


