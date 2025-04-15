module Decoder38(x, y, z, D0, D1, D2, D3, D4, D5, D6, D7);
input x, y, z;
output D0, D1, D2, D3, D4, D5, D6, D7;
reg D0, D1, D2, D3, D4, D5, D6, D7;

always @(x, y, z)
begin
    D0 = 0; D1 = 0; D2 = 0; D3 = 0; D4 = 0; D5 = 0; D6 = 0; D7 = 0;
    case({x, y, z})
    3'b111 : begin
        D7 = 1;
    end
    3'b110 : begin
        D6 = 1;
    end
    3'b101 : begin
        D5 = 1;
    end
    3'b100 : begin
        D4 = 1;
    end
    3'b011 : begin
        D3 = 1;
    end
    3'b010 : begin
        D2 = 1;
    end
    3'b001 : begin
        D1 = 1;
    end
    3'b000 : begin
        D0 = 1;
    end
    endcase
end
endmodule
