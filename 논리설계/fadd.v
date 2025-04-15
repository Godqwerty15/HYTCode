module fadd(x, y, z, s, c);
input x, y, z;
output s, c;

wire temp_sum, temp_c1, temp_c2;

HalfAdder u0(.x(x), .y(y), .s(temp_sum), .c(temp_c1));

HalfAdder u1(.x(temp_sum), .y(z), .s(s), .c(temp_c2));

or2 u3(.a(temp_c2), .b(temp_c1), .o(c));

endmodule
