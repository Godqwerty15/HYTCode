module Encoder83(D0, D1, D2, D3, D4, D5, D6, D7, x, y, z);
input D0, D1, D2, D3, D4, D5, D6, D7;
output x, y, z;
reg x, y, z;

always @(D0 or D1 or D2 or D3 or D4 or D5 or D6 or D7)
begin
    case (1'b1)
        D7: {x, y, z} = 3'b111;
        D6: {x, y, z} = 3'b110;
        D5: {x, y, z} = 3'b101;
        D4: {x, y, z} = 3'b100;
        D3: {x, y, z} = 3'b011;
        D2: {x, y, z} = 3'b010;
        D1: {x, y, z} = 3'b001;
        D0: {x, y, z} = 3'b000;
        default: {x, y, z} = 3'b000;
    endcase
end

endmodule
