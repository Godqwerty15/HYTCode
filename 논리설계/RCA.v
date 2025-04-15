module RCA(x0, y0, x1, y1, x2, y2, x3, y3, C_in, C_out, sum1, sum2, sum3, sum4);
input x0, y0, x1, y1, x2, y2, x3, y3, C_in;
output sum1, sum2, sum3, sum4, C_out;
wire temp0, temp1, temp2;
fadd u0(.x(x0), .y(y0), .z(C_in), .s(sum1), .c(temp0));
fadd u1(.x(x1), .y(y1), .z(temp0), .s(sum2), .c(temp1));
fadd u2(.x(x2), .y(y2), .z(temp1), .s(sum3), .c(temp2));
fadd u3(.x(x3), .y(y3), .z(temp2), .s(sum4), .c(C_out));
endmodule
