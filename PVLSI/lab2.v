module inversor(intrare,iesire);
input intrare;
output iesire;

supply1 VDD;
supply0 VSS;

PMOS(iesire,VDD,intrare);
NMOS(iesire,VSS,intrare);
endmodule

module test_inv();
reg in1;
wire out1;

inversor inv1(in1 , out1);

initial begin
in1 = 1'b0;
#5 in1 = 1'b1;
#10 in1 = 1'b0;
end;

initial monitor($time,"out1=%b,in1=%b",out1,in1);

endmodule
