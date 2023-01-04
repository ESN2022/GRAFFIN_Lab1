	component Lab1_qsys is
		port (
			clk_clk      : in  std_logic                    := 'X'; -- clk
			pio_0_export : out std_logic_vector(7 downto 0);        -- export
			rst_reset_n  : in  std_logic                    := 'X'; -- reset_n
			pio_1_export : in  std_logic                    := 'X'  -- export
		);
	end component Lab1_qsys;

	u0 : component Lab1_qsys
		port map (
			clk_clk      => CONNECTED_TO_clk_clk,      --   clk.clk
			pio_0_export => CONNECTED_TO_pio_0_export, -- pio_0.export
			rst_reset_n  => CONNECTED_TO_rst_reset_n,  --   rst.reset_n
			pio_1_export => CONNECTED_TO_pio_1_export  -- pio_1.export
		);

