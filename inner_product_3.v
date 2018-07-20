module inner_product_3(input clk,
                       input         rst,

                       input [31:0]  u_in,
                       input         u_valid,

                       input [31:0]  v_in,
                       input         v_valid,

                       output [31:0] c);

   wire                              u_out_valid;
   wire [31:0]                       u_data;
   
   fifo_3 u_fifo(.clk(clk), .rst(rst),
                 .in_data_valid(u_valid), .in_data(u_in),
                 .data_valid(u_out_valid),
                 .data_out(u_data));
   
   wire                              v_out_valid;
   wire [31:0]                       v_data;

   fifo_3 v_fifo(.clk(clk), .rst(rst),
                 .in_data_valid(v_valid), .in_data(v_in),
                 .data_valid(v_out_valid),
                 .data_out(v_data));

   wire                              in_valid;
   assign in_valid = u_out_valid && v_out_valid;

   pe accum(.clk(clk),
            .rst(rst),
            .a(u_data),
            .b(v_data),
            .input_valid(in_valid),
            .dbg_c(c));
   
endmodule
