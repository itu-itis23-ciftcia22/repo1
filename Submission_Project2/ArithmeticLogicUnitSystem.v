`timescale 1ns / 1ps
module ArithmeticLogicUnitSystem(

    input [2:0] RF_OutASel, RF_OutBSel, RF_FunSel, // RegisterFile.v
    input [3:0] RF_RegSel, RF_ScrSel,
    
    input [4:0] ALU_FunSel, // ALU.v
    input ALU_WF,
    
    input [1:0] ARF_OutCSel, ARF_OutDSel, //ARFile.v
    input [2:0] ARF_FunSel, ARF_RegSel,
    
    input IR_LH, IR_Write,  // IR
    output [15:0] IROut, // testlerde 16 bitlik IROut da istemis.
    
    input Mem_WR, Mem_CS, // Memory.v
    
    
    input [1:0] MuxASel, MuxBSel, // Mux's
    input MuxCSel,
    
    input Clock, // the whole system uses the same single clock.
    
    input Reset
   
     );
     
     always @(negedge Reset) begin
         RF.R1.Q <= 16'd0;
         RF.R2.Q <= 16'd0;
         RF.R3.Q <= 16'd0;
         RF.R4.Q <= 16'd0;
         RF.S1.Q <= 16'd0;
         RF.S2.Q <= 16'd0;
         RF.S3.Q <= 16'd0;
         RF.S4.Q <= 16'd0;
         ARF.PC.Q <= 16'd0;
         ARF.AR.Q <= 16'd0;
         ARF.SP.Q <= 16'd255;
     end
     
wire [15:0] OutA, OutB, ALUOut, OutC, Address; // Address = OutD
reg [15:0] MuxAOut, MuxBOut;
wire [7:0] MemOut, IROut_MSB, IROut_LSB;
reg [7:0] MuxCOut; 
wire [3:0] Flags;

  
RegisterFile RF(.Clock(Clock), .FunSel(RF_FunSel), .RegSel(RF_RegSel), .ScrSel(RF_ScrSel),
                .I(MuxAOut), .OutASel(RF_OutASel), .OutBSel(RF_OutBSel), .OutA(OutA), .OutB(OutB));
                
ArithmeticLogicUnit ALU(.Clock(Clock), .WF(ALU_WF), .A(OutA), .B(OutB), .FunSel(ALU_FunSel), .ALUOut(ALUOut), .FlagsOut(Flags));


AddressRegisterFile ARF(.Clock(Clock), .I(MuxBOut), .FunSel(ARF_FunSel), .RegSel(ARF_RegSel), .OutCSel(ARF_OutCSel),
                        .OutDSel(ARF_OutDSel), .OutC(OutC), .OutD(Address));  
                        
InstructionRegister IR(.Clock(Clock), .LH(IR_LH), .Write(IR_Write), .I(MemOut), .IROut({IROut_MSB,IROut_LSB}));   

Memory MEM(.Clock(Clock), .WR(Mem_WR), .CS(Mem_CS), .Address(Address), .Data(MuxCOut), .MemOut(MemOut));  


assign IROut = {IROut_MSB,IROut_LSB};
  
always @(*) begin

    case(MuxASel)
        2'b00:  MuxAOut = ALUOut;
        2'b01:  MuxAOut = OutC;
        2'b10:  MuxAOut = {8'd0, MemOut};
        2'b11:  MuxAOut = {8'd0, IROut_LSB};
    endcase
    
    case(MuxBSel)
        2'b00:  MuxBOut = ALUOut;
        2'b01:  MuxBOut = OutC;
        2'b10:  MuxBOut = {8'd0, MemOut};
        2'b11:  MuxBOut = {8'd0, IROut_LSB};
    endcase
    
    case(MuxCSel)
        1'b0:   MuxCOut = ALUOut[7:0];
        1'b1:   MuxCOut = ALUOut[15:8];
    endcase
end                                   

endmodule


