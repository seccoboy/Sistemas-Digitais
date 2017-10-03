module multv(
	input clk,
	input [9:0] x,
	input [9:0] y,
	input reset,
	output [19:0] saida
);

reg[19:0] acumulador = 0;
assign saida = acumulador;
reg[19:0] mult1 = 0;
assign mult1 = x*y;

always @(posedge clk) begin
	if(reset) begin
		acumulador <=mult1;
	end
	else begin
		if(enable) begin
			acumulador <=acumulador + mult1;	
		end
		else begin
			acumulador<=acumulador;
		end
	end
end


endmodule
