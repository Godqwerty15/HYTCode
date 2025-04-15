module MUX(A, B, C, D, S, Out);
input A, B, C, D;
input [1:0]S;
output Out;
assign Out = (S[1] == 0 && S[0] == 0) ? A :
             (S[1] == 0 && S[0] == 1) ? B :
             (S[1] == 1 && S[0] == 0) ? C :
             (S[1] == 1 && S[0] == 1) ? D :
             0;
endmodule
