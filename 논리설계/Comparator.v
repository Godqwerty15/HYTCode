module Comparator(x, y, EQ);
input x, y;
output EQ;
reg EQ;
always @(x, y)
begin
    EQ = 0;
    if(x == y) begin
        EQ = 1;
    end
    if(x != y) begin
        EQ = 0;
    end
end
endmodule
