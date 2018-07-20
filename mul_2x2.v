module mul_2x2(input clk,
               input        rst,

               input [31:0] a_row_0,
               input        a_row_0_valid,

               input [31:0] a_row_1,
               input        a_row_1_valid,

               input [31:0] b_col_0,
               input        b_col_0_valid,

               input [31:0] b_col_1,
               input        b_col_1_valid,

               output [31:0] c00_out,
               output [31:0] c01_out,
               output [31:0] c10_out,
               output [31:0] c11_out);

   wire                      ;

   // Input fifos

   fifo_1 row_0_in(.clk(clk), .rst(rst), 
                   .in_data_valid(a_row_0_valid),
                   .in_data(a_row_0),
                   .data_out(out));

   fifo_2 row_1_in(.clk(clk), .rst(rst), 
                   .in_data_valid(a_row_1_valid),
                   .in_data(a_row_1));

   fifo_1 col_0_in(.clk(clk), .rst(rst), 
                   .in_data_valid(b_col_0_valid),
                   .in_data(b_col_0));

   fifo_2 col_1_in(.clk(clk), .rst(rst), 
                   .in_data_valid(b_col_1_valid),
                   .in_data(b_col_1));
   
   // Row 0
   pe c00(.clk(clk), .rst(rst),
          .dbg_c(c00_out));
   pe c01(.clk(clk), .rst(rst), .dbg_c(c01_out));

   // Row 1
   pe c10(.clk(clk), .rst(rst), .dbg_c(c10_out));
   pe c11(.clk(clk), .rst(rst), .dbg_c(c11_out));

endmodule
