module pe(input clk,
          input         rst,

          input [31:0]  a,
          input [31:0]  b,

          input input_valid,

          output [31:0] dbg_c);

   reg [31:0]   c;
   
   always @(posedge clk or negedge rst) begin
      // $display("a = ", a);
      // $display("b = ", b);      

      if (!rst) begin
         c <= 0;
      end else if (input_valid) begin
         c <= c + a*b;
      end
   end

   assign dbg_c = c;

endmodule
