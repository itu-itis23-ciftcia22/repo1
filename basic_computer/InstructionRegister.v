`timescale 1ns / 1ps
module InstructionRegister(
    input [7:0] I,   // 8-bit input bus
    input LH,          // L'H signal
    input Clock,          // Clock input
    input Write,        // Reset input
    output reg [15:0] IROut // 16-bit Instruction Register
);

always @(posedge Clock)
 begin
    if (Write == 1)
    begin
        case(LH)
            1'b1 : IROut[15:8] <= I;
            1'b0:  IROut[7:0] <= I; 
        endcase 
    end
    else IROut <= IROut; 
 end
endmodule