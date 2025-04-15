module Comparator4(x, y, EQ, AGB, ALB);
input [3:0]x, y;
output EQ, AGB, ALB;
reg EQ, AGB, ALB;
always @(x, y)
begin
    EQ = 0; AGB = 0; ALB = 0;
    if(x == y) begin
        EQ = 1;
    end
    if(x > y) begin
        AGB = 1;
    end
    if(x < y) begin
        ALB = 1;
    end
end
endmodule
