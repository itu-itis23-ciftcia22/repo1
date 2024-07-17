`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12.03.2024 19:19:00
// Design Name: 
// Module Name: Register
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Register (
    input Clock ,
    input [2:0] FunSel, // 3-bit control signals
    input E,            // Enable input
    input [15:0] I,     // Input data
    output reg [15:0] Q      // Output data
);

always @(posedge Clock) 
  begin

    if(E == 0)    // Independent from FunSel
    begin
      Q <= Q;     // Retain value
    end

    else
    begin 
      case (FunSel)
        3'b000: Q <= Q - 1;         // Decrement
        3'b001: Q <= Q + 1;         // Increment
        3'b010: Q <= I;                 // Load
        3'b011: Q <= 16'h0;             // Clear
        3'b100: Q <= {8'h0, I[7:0]};    // Clear lower 8 bits, write lower 8 bits of I
        3'b101: Q <= {Q[15:8],I[7:0]};       // Only write lower 8 bits of I
        3'b110: Q <= {I[7:0], Q[7:0]};      // Only write upper 8 bits of I
        3'b111: 
        begin                   
            if (I[7] == 1)      // Sign extend and write lower 8 bits of I
             begin
                Q <= {8'hFF, I[7:0]};  
             end
            else 
             begin
                Q <= {8'h0, I[7:0]};
             end
        end
        default: Q <= Q;        // Retain value (gerekli mi bilmiom zaten her case i incelemis olduk.)
     endcase
    end

  end
endmodule