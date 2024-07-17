`timescale 1ns / 1ps
module ControlUnit(
    input Clock,
    input Reset,
    input [15:0] IROut,
    input  Z,
    output wire [2:0] RF_OutASel, RF_OutBSel, RF_FunSel,
    output wire [3:0] RF_RegSel, RF_ScrSel,
    output wire ALU_WF,
    output wire [4:0] ALU_FunSel,
    output wire [1:0] ARF_OutCSel, ARF_OutDSel,
    output wire [2:0] ARF_FunSel, ARF_RegSel,
    output wire IR_LH, IR_Write,
    output wire Mem_WR, Mem_CS,
    output wire MuxCSel,
    output wire [1:0] MuxASel, MuxBSel,
    output reg [7:0] T
    
);

wire Reset2;
reg [3:0] SC;
reg[33:0] D ;
reg S;
reg [1:0]SREG1,SREG2;
reg[3:0] DSTREG,RREGD;
reg[2:0] RREGS;
reg [3:0] DS1;
reg [7:0] DS12;

always @(posedge Clock) begin
    if( Reset2 ) begin
        SC <= 0;
        D <= 33'd0;
        end
    else begin
        SC <= SC + 1; 
        end
end  
always @ (Reset) begin
    SC <= 0;
end

always @(SC) begin

    T = 8'd0;
    T[SC] = 1'b1;

end
always @(posedge T[2]) begin
        #0.1;
        D = 33'd0;
        D[IROut[15:10]] = 1;
        S = IROut[9];
        case (IROut[5:3]) // sreg1, ARF de ise arf_outc = SREG1, RF de ise rf_out={1'b0,SREG1}
        0: SREG1 = IROut[4:3];
        1: SREG1 = IROut[4:3]; 
        2: SREG1 = 2'b11;
        3: SREG1 = 2'b10;
        4: SREG1 = IROut[4:3];
        5: SREG1 = IROut[4:3];
        6: SREG1 = IROut[4:3];
        7: SREG1 = IROut[4:3];
        endcase
        case (IROut[2:0]) // sreg2, ARF de ise arf_outc = SREG2, RF de ise rf_out= {1'b0,SREG2}
        0: SREG2 = IROut[1:0];
        1: SREG2 = IROut[1:0]; 
        2: SREG2 = 2'b11;
        3: SREG2 = 2'b10;
        4: SREG2 = IROut[1:0];
        5: SREG2 = IROut[1:0];
        6: SREG2 = IROut[1:0];
        7: SREG2 = IROut[1:0];
        endcase
        case (IROut[8:6]) // dstreg, ARF de ise arf_regsel = DSTREG[2:0], RF de ise rf_regsel = DSTREG
        0: DSTREG = 4'b0011;
        1: DSTREG = 4'b0011;
        2: DSTREG = 4'b0110;
        3: DSTREG = 4'b0101;
        4: DSTREG = 4'b0111;
        5: DSTREG = 4'b1011;
        6: DSTREG = 4'b1101;
        7: DSTREG = 4'b1110;
        endcase
        case (IROut[9:8]) // Rx destination iken , RF_RegSel kullanacak
        0: RREGD = 4'b0111;
        1: RREGD = 4'b1011;
        2: RREGD = 4'b1101;
        3: RREGD = 4'b1110;
        endcase
        case (IROut[9:8]) // Rx source iken , RF_Out kullanacak
        0: RREGS = 3'b000;
        1: RREGS = 3'b001;
        2: RREGS = 3'b010;
        3: RREGS = 3'b011;
        endcase

        DS1 = 4'd0;
        DS1[{IROut[8],IROut[5]}] = 1'b1;
        /*
        case({IR[8],IR[5]})  
        0:arf to arf 0 s1 to arf
        1:rf to arf 1
        2:arf to rf 2 s1 to rf
        3:rf to rf 3
        endcase
        */
        DS12 = 8'd0;
        DS12[{IROut[8],IROut[5],IROut[2]}] = 1'b1;
        /*
        case({IR[8],IR[5],IR[2]}) 
        0:arf,arf to arf 0 s1 ve s2 to arf
        1:arf,rf to arf 1 s1,rf to arf
        2:rf,arf to arf 2 rf,s1 to arf
        3:rf,rf to arf 3
        4:arf,arf to rf 4 s1 ve s2 to rf
        5:arf,rf to rf 5 s1,rf to rf
        6:rf,arf to rf 6 rf,s1 to rf
        7:rf,rf to rf 7
        endcase
        */
end

assign ALU_FunSel = (D[0] | (D[1] & ~Z) | (D[2] & Z)) ? 5'b10100 :
                     ((D[4]&(T[3]|T[4])) | D[5] | D[6] | D[24] | D[19] | D[30]) ? 5'b10000 :
                     (D[7]) ? 5'b11011 :
                     (D[8]) ? 5'b11100 :
                     (D[9]) ? 5'b11101 :
                     (D[10]) ? 5'b11110 :
                     (D[11]) ? 5'b11111 :
                     (D[14]) ? 5'b10010 :
                     (D[12]) ? 5'b10111 :
                     (D[13]) ? 5'b11000 :
                     (D[15]) ? 5'b11001 :
                     (D[16]) ? 5'b11010 :
                     (D[21]) ? 5'b10100 :
                     (D[22]) ? 5'b10101 :
                     (D[23]) ? 5'b10110 :
                     (D[25]) ? 5'b10100 :
                     (D[26]) ? 5'b10110 :
                     (D[27]) ? 5'b10111 :
                     (D[28]) ? 5'b11000 :
                     (D[29]) ? 5'b11001 :
                     (D[33] & T[4]) ? 5'b10100 :
                     (D[33] & (T[5] | T[6])) ? 5'b10000 :
                     5'b10000;


assign RF_OutASel = (D[0] | (D[1] & !Z) | (D[2] & Z)) ? 3'b100 :
                     (D[4]&(T[3]|T[4])) ? RREGS :
                     (D[5] | D[6]) & (T[2]) & ((DS1[1]) | (DS1[3])) ? {1'b0, SREG1} :
                     (D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & ((DS1[0]) | (DS1[2])) ? 3'b100 :
                     (D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & (T[2]) & ((DS1[1]) | (DS1[3])) ? {1'b0, SREG1} :
                     (D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29])
                     & ((DS12[0]) | (DS12[4]) | (DS12[1]) | (DS12[5])) ? 3'b100 :
                     (D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29])
                     & ((DS12[2]) | (DS12[6]) | (DS12[3]) | (DS12[7])) ? {1'b0, SREG1} :
                     (D[19]) ? RREGS :
                     (D[30]) & ((T[3]) | (T[4])) ? 3'b100 :
                     (D[30]) & (T[5]) ? RREGS :
                     (D[33]) & (T[4]) ? 3'b100 :
                     (D[33]) & ((T[5]) | (T[6])) ? RREGS :
                     3'b100; // default 100/S1

assign RF_OutBSel = (D[0] | (D[1] & !Z) | (D[2] & Z)) ? 3'b101 :
                    (D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29])
                    & ((DS12[0]) | (DS12[4]) | (DS12[2]) | (DS12[6])) ? 3'b101 :
                    (D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29])
                    & ((DS12[1]) | (DS12[5]) | (DS12[3]) | (DS12[7])) ? {1'b0, SREG2} :
                    (D[33]) & (T[4]) ? 3'b101 :
                    3'b101; // default 101/S2

assign RF_FunSel =  (D[0] | (D[1] & !Z) | (D[2] & Z)) & (T[2]) ? 3'b111 : // value atamasi , signed olarak atanacak.
                    (D[0] | (D[1] & !Z) | (D[2] & Z)) & (T[3]) ? 3'b010 : // pc atamasi
                    (D[0] | (D[1] & !Z) | (D[2] & Z)) & (T[4]) ? 3'b011 : // clear 
                    (D[3]) & (T[2]) ? 3'b101 :
                    (D[3]) & (T[3]) ? 3'b110 :
                    (D[5] | D[6]) & (T[2]) & (DS1[2] | DS1[3]) ? 3'b010 :
                    (D[5]) & (T[3]) & (DS1[2] | DS1[3]) ? 3'b001 :
                    (D[6]) & (T[3]) & (DS1[2] | DS1[3]) ? 3'b000 :
                    (D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & (T[2] | ((T[3]) & (DS1[3]))) & (DS1[0] | DS1[2] | DS1[3]) ? 3'b010 :
                    (D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & (((T[3]) & (DS1[0])) | ((T[4]) & (DS1[2]))) ? 3'b011 :
                    (D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) &
                    (((T[2]) & ((DS12[0]) | (DS12[4]) | (DS12[1]) | (DS12[5]) | (DS12[2]) | (DS12[6]) | (DS12[7]))) |
                    ((T[3]) & ((DS12[0]) | (DS12[4]) | (DS12[5]) | (DS12[6]))) | ((T[4]) & (DS12[4]))) ? 3'b010 :
                    (D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) &
                    (((T[3]) & ((DS12[1]) | (DS12[2]))) | ((T[4]) & ((DS12[0]) | (DS12[5]) | (DS12[6]))) |
                    ((T[5]) & (DS12[4]))) ? 3'b011 :
                    (D[17]) & (T[2]) ? 3'b110 :
                    (D[20]) & (T[2]) ? 3'b101 :
                    (D[18]) & (T[2]) ? 3'b101 :
                    (D[18]) & (T[3]) ? 3'b110 :
                    (D[30]) & (T[2]) ? 3'b010 :
                    (D[30]) & (T[5]) ? 3'b011 :
                    (D[32]) & (T[2]) ? 3'b111 :
                    (D[33]) & (T[2]) ? 3'b111 :
                    (D[33]) & (T[3]) ? 3'b010 :
                    (D[33]) & (T[6]) ? 3'b011 :
                    3'bx;

assign RF_RegSel =  (D[3]) ? RREGD :
                    (D[5] | D[6]) & (T[2] | (T[3])) & (DS1[2] | DS1[3]) ? DSTREG :
                    (D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & (((T[3]) & (DS1[2])) | ((T[2]) & (DS1[3]))) ? DSTREG :
                    (D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) &
                    (((T[4]) & (DS12[4])) | ((T[3]) & ((DS12[5]) | (DS12[6]))) | ((T[2]) & (DS12[7]))) ? DSTREG :
                    (D[17] | D[20])  ? RREGD :
                    (D[18]) ? RREGD :
                    (D[32]) & (T[2]) ? RREGD :
                    4'b1111; // Varsayılan olarak 1111 atanır

assign RF_ScrSel = ((D[0] | (D[1] & !Z) | (D[2] & Z)) & T[2]) ? 4'b0111 :
                    ((D[0] | (D[1] & !Z) | (D[2] & Z)) & T[3]) ? 4'b1011 :
                    ((D[0] | (D[1] & !Z) | (D[2] & Z)) & T[4]) ? 4'b0011 :
                    ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & ((T[2]) | T[3]) & DS1[0]) ? 4'b0111 :
                    ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & ((T[2]) | T[4]) & DS1[3]) ? 4'b0111 :
                    ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) &
                     (((T[2]) & ((DS12[0]) | (DS12[4]))) | ((T[2]) & ((DS12[1]) | (DS12[5]))) | ((T[3]) & (DS12[1])) | ((T[4]) & (DS12[5])))) ? 4'b0111 :
                    ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) &
                     (((T[3]) & ((DS12[0]) | (DS12[4]))) | ((T[2]) & ((DS12[2]) | (DS12[6]))) | ((T[3]) & (DS12[2])) | ((T[4]) & (DS12[6])))) ? 4'b1011 :
                    ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) &
                     (((T[4]) & (DS12[0])) | ((T[5]) & (DS12[4])))) ? 4'b0011 :
                    ((D[30]) & ((T[2]) | (T[5]))) ? 4'b0111 :
                    ((D[33]) & (T[2])) ? 4'b0111 :
                    ((D[33]) & (T[3])) ? 4'b1011 :
                    ((D[33]) & (T[6])) ? 4'b0011 :
                    4'b1111; // Varsayılan olarak 1111 atanır

assign MuxBSel = ((D[0] | (D[1] & !Z) | (D[2] & Z)) & T[4]) ? 2'b00 :
                 ((D[5] | D[6]) & T[2] & DS1[0]) ? 2'b01 :
                 ((D[5] | D[6]) & T[2] & DS1[1]) ? 2'b00 :
                 ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & DS1[0] & T[3]) ? 2'b00 :
                 ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & DS1[1] & T[2]) ? 2'b00 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[0] & T[4]) ? 2'b00 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[1] & T[3]) ? 2'b00 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[2] & T[3]) ? 2'b00 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[3] & T[2]) ? 2'b00 :
                 (D[30] & T[5]) ? 2'b00 :
                 (D[31] & T[2]) ? 2'b10 :
                 (D[31] & T[4]) ? 2'b10 :
                 (D[33] & T[4]) ? 2'b00 :
                 2'bx; // Varsayılan olarak x atanır

assign MuxASel = ((D[0] | (D[1] & ~Z) | (D[2] & Z)) & T[2]) ? 2'b11 :
                 ((D[0] | (D[1] & ~Z) | (D[2] & Z)) & T[3]) ? 2'b01 :
                 (D[3]) ? 2'b10 :
                 ((D[5] | D[6]) & T[2] & DS1[2]) ? 2'b01 :
                 ((D[5] | D[6]) & T[2] & DS1[3]) ? 2'b00 :
                 ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[2] & DS1[0]) ? 2'b01 :
                 ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[2] & DS1[2]) ? 2'b01 :
                 ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[3] & DS1[2]) ? 2'b00 :
                 ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[2] & DS1[3]) ? 2'b00 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[0] | DS12[4]) & T[2]) ? 2'b01 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[0] | DS12[4]) & T[3]) ? 2'b01 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[4]) & T[4]) ? 2'b00 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[1] | DS12[5]) & T[2]) ? 2'b01 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[5]) & T[3]) ? 2'b00 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[2] | DS12[6]) & T[2]) ? 2'b01 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[6]) & T[3]) ? 2'b00 :
                 ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[7]) & T[2]) ? 2'b00 :
                 ((D[17] | D[20]) & T[2]) ? 2'b11 :
                 (D[18]) ? 2'b10 :
                 (D[30] & T[2]) ? 2'b01 :
                 (D[32] & T[2]) ? 2'b11 :
                 (D[33] & T[2]) ? 2'b11 :
                 (D[33] & T[3]) ? 2'b01 :
                 2'bx; // Varsayılan olarak x atanır

assign MuxCSel = (D[4] & T[3]) ? 1'b1 : // tabanda msb olacak
                 (D[4] & T[4]) ? 1'b0 : // ustte lsb olacak
                 (D[19] & T[2]) ? 1'b0 :
                 (D[19] & T[3]) ? 1'b1 :
                 (D[30] & T[3]) ? 1'b1 :
                 (D[30] & T[4]) ? 1'b0 :
                 (D[33] & T[5]) ? 1'b0 :
                 (D[33] & T[6]) ? 1'b1 :
                 1'bx; // Varsayılan olarak x atanır

 assign IR_LH = 
        (T[0]) ? 1'b0 :
        (T[1]) ? 1'b1 :
        1'bx;

assign IR_Write = 
                (T[0] || T[1]) ? 1'b1 :
                1'b0;                 

assign Mem_CS = (T[0]| T[1] | D[3] | (D[4]&(T[3]|T[4])) | D[18] | D[19] | (D[30] & (T[3] | T[4])) | (D[31] & (T[2] | T[4])) | (D[33] & (T[5] | T[6]))) ? 1'b0 : 1'b1;

assign Mem_WR = (T[0] | T[1]) ? 1'b0 :
                (D[3]) ? 1'b0 :
                (D[4]&(T[3]|T[4])) ? 1'b1 :
                (D[18]) ? 1'b0 :
                (D[19]) ? 1'b1 :
                (D[30] & (T[3] | T[4])) ? 1'b1 :
                (D[31] & (T[2] | T[4])) ? 1'b0 :
                (D[33] & (T[5] | T[6])) ? 1'b1 :
                1'bx;

assign ARF_OutCSel = ((D[0] | (D[1] & ~Z) | (D[2] & Z)) & T[3]) ? 2'b00 :
                     ((D[5] | D[6]) & T[2] & (DS1[0] | DS1[2])) ? SREG1 :
                     ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[2] & DS1[0]) ? SREG1 :
                     ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[2] & DS1[2]) ? SREG1 :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[0] | DS12[4]) & T[2]) ? SREG1 :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[0] | DS12[4]) & T[3]) ? SREG2 :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[1] | DS12[5]) & T[2]) ? SREG1 :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[2] | DS12[6]) & T[2]) ? SREG2 :
                     (D[30] & T[2]) ? 2'b00 :
                     (D[33] & T[3]) ? 2'b10 :
                     2'bx;

assign ARF_OutDSel = (T[0] | T[1]) ? 2'b00 :
                     (D[3]) ? 2'b11 :
                     (D[4] &(T[3]|T[4])) ? 2'b11:
                     (D[18] | D[19]) ? 2'b10 :
                     (D[30] & (T[3] | T[4])) ? 2'b11 :
                     (D[31] & T[2]) ? 2'b11 :
                     (D[31] & T[4]) ? 2'b11 :
                     (D[33] & (T[5] | T[6])) ? 2'b10 :
                     2'bx;

assign ARF_FunSel =  (T[0] | T[1]) ? 3'b001 :
                     ((D[0] | (D[1] & ~Z) | (D[2] & Z)) & T[4]) ? 3'b010 :
                     (D[3]) ? 3'b001 :
                     (D[4]&(T[2]|T[3])) ? 3'b000 :
                     ((D[5] | D[6]) & T[2] & (DS1[0] | DS1[1])) ? 3'b010 :
                     ((D[5] & T[3]) & (DS1[0] | DS1[1])) ? 3'b001 :
                     ((D[6] & T[3]) & (DS1[0] | DS1[1])) ? 3'b000 :
                     ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[3] & DS1[0]) ? 3'b010 :
                     ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[2] & DS1[1]) ? 3'b010 :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[0] & T[4]) ? 3'b010 :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[1] & T[3]) ? 3'b010 :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[2] & T[3]) ? 3'b010 :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[3] & T[2]) ? 3'b010 :
                     D[18]&(T[2]) ? 3'b001 :
                     D[19]&(T[2]) ? 3'b000 :
                     (D[30] &(T[2]|T[3])) ? 3'b000 :
                     (D[30] & T[5]) ? 3'b010 :
                     (D[31] & T[2]) ? 3'b101 :
                     (D[31] & T[3]) ? 3'b001 :
                     (D[31] & T[4]) ? 3'b110 :
                     (D[33] & T[4]) ? 3'b010 :
                     (D[33] & (T[5] | T[6])) ? 3'b001 :
                     3'bx;

assign ARF_RegSel =  (T[0] | T[1]) ? 3'b011 :
                     ((D[0] | (D[1] & ~Z) | (D[2] & Z)) & T[4]) ? 3'b011 :
                     (D[3]) ? 3'b110 :
                     (D[4]&(T[2]|T[3])) ? 3'b110 :
                     ((D[5] | D[6]) & (T[2] | T[3]) & (DS1[0] | DS1[1])) ? DSTREG[2:0] :
                     ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[3] & DS1[0]) ? DSTREG[2:0] :
                     ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & T[2] & DS1[1]) ? DSTREG[2:0] :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[0] & T[4]) ? DSTREG[2:0] :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[1] & T[3]) ? DSTREG[2:0] :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[2] & T[3]) ? DSTREG[2:0] :
                     ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[3] & T[2]) ? DSTREG[2:0] :
                     (D[18] | D[19]) & T[2] ? 3'b101 :
                     (D[30] & (T[3] | T[2])) ? 3'b110 :
                     (D[30] & T[5]) ? 3'b011 :
                     (D[31] & T[2]) ? 3'b011 :
                     (D[31] & T[3]) ? 3'b110 :
                     (D[31] & T[4]) ? 3'b011 :
                     (D[33] & T[4]) ? 3'b101 :
                     (D[33] & (T[5] | T[6])) ? 3'b101 :
                     3'b111;

assign Reset2 = (D[1]&Z | D[2]& ~Z) |
                ((D[0] | (D[1] & ~Z) | (D[2] & Z)) & T[4]) |
                (D[3] & T[3]) |
                (D[4] & T[4]) |
                ((D[5] | D[6]) & T[3]) |
                ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & DS1[0] & T[3]) |
                ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & DS1[1] & T[2]) |
                ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & DS1[2] & T[4]) |
                ((D[7] | D[8] | D[9] | D[10] | D[11] | D[14] | D[24]) & DS1[3] & T[2]) |
                ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[0] & T[4]) |
                ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[4] & T[5]) |
                ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[1] & T[3]) |
                ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[5] & T[4]) |
                ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[2] & T[3]) |
                ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & DS12[6] & T[4]) |
                ((D[12] | D[13] | D[15] | D[16] | D[21] | D[22] | D[23] | D[25] | D[26] | D[27] | D[28] | D[29]) & (DS12[3] | DS12[7]) & T[2]) |
                ((D[17] | D[20]) & T[2]) |
                ((D[18] | D[19]) & T[3]) |
                (D[30] & T[5]) |
                (D[31] & T[4]) |
                (D[32] & T[2]) |
                (D[33] & T[6]);

assign ALU_WF = (D[24] | D[25] | D[26] | D[27] | D[28] | D[29]) ? S : 1'b0;                                    

endmodule  
module CPUSystem (
    input Clock,
    output wire [7:0] T,
    input  Reset
);
    wire [2:0] RF_OutASel, RF_OutBSel, RF_FunSel;
    wire [3:0] RF_RegSel, RF_ScrSel;
    wire[4:0] ALU_FunSel;
    wire ALU_WF;
    wire [1:0] ARF_OutCSel, ARF_OutDSel;
    wire [2:0] ARF_RegSel, ARF_FunSel;
    wire IR_LH, IR_Write;
    wire Mem_WR, Mem_CS;
    wire [1:0] MuxASel, MuxBSel;
    wire MuxCSel;
    wire [15:0] IROut;
    wire Z;
    
    ArithmeticLogicUnitSystem _ALUSystem(.RF_OutASel(RF_OutASel), 
            .RF_OutBSel(RF_OutBSel), 
            .RF_FunSel(RF_FunSel),
            .RF_RegSel(RF_RegSel),
            .RF_ScrSel(RF_ScrSel),
            .ALU_FunSel(ALU_FunSel),
            .ALU_WF(ALU_WF),
            .ARF_OutCSel(ARF_OutCSel), 
            .ARF_OutDSel(ARF_OutDSel), 
            .ARF_FunSel(ARF_FunSel),
            .ARF_RegSel(ARF_RegSel),
            .IR_LH(IR_LH),
            .IR_Write(IR_Write),
            .Mem_WR(Mem_WR),
            .Mem_CS(Mem_CS),
            .MuxASel(MuxASel),
            .MuxBSel(MuxBSel),
            .MuxCSel(MuxCSel),
            .Clock(Clock),
            .IROut(IROut),
            .Reset(Reset));
   
    ControlUnit _Control(.RF_OutASel(RF_OutASel), 
                        .RF_OutBSel(RF_OutBSel), 
                        .RF_FunSel(RF_FunSel),
                        .RF_RegSel(RF_RegSel),
                        .RF_ScrSel(RF_ScrSel),
                        .ALU_FunSel(ALU_FunSel),
                        .ALU_WF(ALU_WF),
                        .ARF_OutCSel(ARF_OutCSel), 
                        .ARF_OutDSel(ARF_OutDSel), 
                        .ARF_FunSel(ARF_FunSel),
                        .ARF_RegSel(ARF_RegSel),
                        .IR_LH(IR_LH),
                        .IR_Write(IR_Write),
                        .Mem_WR(Mem_WR),
                        .Mem_CS(Mem_CS),
                        .MuxASel(MuxASel),
                        .MuxBSel(MuxBSel),
                        .MuxCSel(MuxCSel),
                        .Clock(Clock),
                        .IROut(IROut),
                        .Z(Z),
                        .Reset(Reset),
                        .T(T)
                        );

assign Z = _ALUSystem.ALU.FlagsOut[3];  
  
  
  
endmodule