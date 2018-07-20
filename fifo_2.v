module fifo_3(input clk,
              input         rst,

              input         in_data_valid,
              input         [31:0] in_data,

              output [31:0] data_out,
              output        data_valid);

   reg               data_valid_reg_0;
   reg               data_valid_reg_1;

   reg [31:0]        data_out_0;
   reg [31:0]        data_out_1;
   
   always @(posedge clk or negedge rst) begin
      if (!rst) begin
         data_valid_reg_0 <= 0;
         data_valid_reg_1 <= 0;

         data_out_0 <= 0;
         data_out_1 <= 0;

      end else begin

         data_valid_reg_0 <= in_data_valid;
         data_valid_reg_1 <= data_valid_reg_0;

         data_out_0 <= in_data;
         data_out_1 <= data_out_0;

      end
   end

   assign data_valid = data_valid_reg_1;
   assign data_out = data_out_1;
   
endmodule
