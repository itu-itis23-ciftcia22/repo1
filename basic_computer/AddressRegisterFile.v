`timescale 1ns / 1ps
module AddressRegisterFile(
    input [15:0] I,
    input Clock, 
    input [2:0] FunSel,
    input [2:0] RegSel,
    input [1:0] OutCSel,
    input [1:0] OutDSel,
    output reg [15:0] OutC,
    output reg [15:0] OutD

);
wire [15:0]  QPC, QAR, QSP;
reg EPC, EAR, ESP;

Register PC(.Clock(Clock), .FunSel(FunSel), .E(EPC), .I(I), .Q(QPC));
Register AR(.Clock(Clock), .FunSel(FunSel), .E(EAR), .I(I), .Q(QAR));
Register SP(.Clock(Clock), .FunSel(FunSel), .E(ESP), .I(I), .Q(QSP));

always @(*)
begin
    if (!RegSel[2]) EPC = 1'b1;
    else EPC = 1'b0;
    if (!RegSel[1]) EAR = 1'b1;
    else EAR = 1'b0;
    if (!RegSel[0]) ESP = 1'b1;
    else ESP = 1'b0;
end

always @(*)
begin
    case (OutCSel)
       2'b00: OutC = QPC;
       2'b01: OutC = QPC;
       2'b10: OutC = QAR;
       2'b11: OutC = QSP;     
    endcase
end
always @(*)
begin

    case (OutDSel)
       2'b00: OutD = QPC;
       2'b01: OutD = QPC;
       2'b10: OutD = QAR;
       2'b11: OutD = QSP;
    endcase
end

endmodule
