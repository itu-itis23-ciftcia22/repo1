`timescale 1ns / 1ps
module RegisterFile (
    input Clock,
    input [2:0] FunSel,
    input [3:0] RegSel,
    input [3:0] ScrSel,
    input [15:0] I,
    input [2:0] OutASel,  
    input [2:0] OutBSel, 
    output reg [15:0] OutA,
    output reg [15:0] OutB
);
wire [15:0]  QR1, QR2, QR3, QR4, QS1, QS2, QS3, QS4;
reg ER1, ER2, ER3, ER4, ES1, ES2, ES3, ES4;


// Instantiate Register module for each register
Register R1(.Clock(Clock), .FunSel(FunSel), .E(ER1), .I(I), .Q(QR1));
Register R2(.Clock(Clock), .FunSel(FunSel), .E(ER2), .I(I), .Q(QR2));
Register R3(.Clock(Clock), .FunSel(FunSel), .E(ER3), .I(I), .Q(QR3));
Register R4(.Clock(Clock), .FunSel(FunSel), .E(ER4), .I(I), .Q(QR4));
Register S1(.Clock(Clock), .FunSel(FunSel), .E(ES1), .I(I), .Q(QS1));
Register S2(.Clock(Clock), .FunSel(FunSel), .E(ES2), .I(I), .Q(QS2));
Register S3(.Clock(Clock), .FunSel(FunSel), .E(ES3), .I(I), .Q(QS3));
Register S4(.Clock(Clock), .FunSel(FunSel), .E(ES4), .I(I), .Q(QS4));

 // hangi registerlar kullan ma a  k
always @(*) begin
 if (!RegSel[3]) ER1 = 1'b1;
 else ER1 = 1'b0;
 if (!RegSel[2]) ER2 = 1'b1;
 else ER2 = 1'b0;
 if (!RegSel[1]) ER3 = 1'b1;
 else ER3 = 1'b0;
 if (!RegSel[0]) ER4 = 1'b1;
 else ER4 = 1'b0;
 end
 always @(*) begin
 if (!ScrSel[3]) ES1 = 1'b1;
 else ES1 = 1'b0;
 if (!ScrSel[2]) ES2 = 1'b1;
 else ES2 = 1'b0;
 if (!ScrSel[1]) ES3 = 1'b1;
 else ES3 = 1'b0;
 if (!ScrSel[0]) ES4 = 1'b1;  
 else ES4 = 1'b0; 
 end
           
                
always @(*) begin
   case (OutASel)
       3'b000: OutA = QR1;
       3'b001: OutA = QR2;
       3'b010: OutA = QR3;
       3'b011: OutA = QR4;
       3'b100: OutA = QS1;
       3'b101: OutA = QS2;
       3'b110: OutA = QS3;
       3'b111: OutA = QS4;
   endcase
   
end
always @(*) begin
   case (OutBSel)
       3'b000: OutB = QR1;
       3'b001: OutB = QR2;
       3'b010: OutB = QR3;
       3'b011: OutB = QR4;
       3'b100: OutB = QS1;
       3'b101: OutB = QS2;
       3'b110: OutB = QS3;
       3'b111: OutB = QS4;
   endcase

 end
 



endmodule

  
