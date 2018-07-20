module pe(input clk,
          input        rst,

          input [31:0] a,
          input [31:0] b,

          output [31:0] dbg_c);

   reg [31:0]   c;
   
   always @(posedge clk or negedge rst) begin
      if (!rst) begin
         c <= 0;
      end else begin
         c <= c + a*b;
      end
   end

   assign dbg_c = c;

endmodule
