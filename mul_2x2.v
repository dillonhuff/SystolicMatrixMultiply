module mul_2x2(input clk,
               input rst);

   // Input fifos

   fifo_1 row_0_in(.clk(clk), .rst(rst));
   fifo_2 row_1_in(.clk(clk), .rst(rst));

   fifo_1 col_0_in(.clk(clk), .rst(rst));
   fifo_2 col_1_in(.clk(clk), .rst(rst));
   
   // Row 0
   pe c00(.clk(clk), .rst(rst));
   pe c01(.clk(clk), .rst(rst));

   // Row 1
   pe c10(.clk(clk), .rst(rst));
   pe c11(.clk(clk), .rst(rst));

endmodule
