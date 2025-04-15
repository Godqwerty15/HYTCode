module sub2(x, y, D, B);
input x, y;
output D, B;
assign D = x ^ y;
reg B;
always @(x, y)
begin
    B = 0;
    if(x == 0 && y == 1) begin
        B = 1;
    end
end
endmodule
