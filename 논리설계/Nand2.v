module Nand2(x, y, s);
input x, y;
output s;
wire temp0;
and3 u0(.x(x), .y(y), .s(temp0));
Not2 u1(.x(temp0), .s(s));
endmodule
