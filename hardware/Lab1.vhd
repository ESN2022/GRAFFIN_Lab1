library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Lab1 is
	port (
		clk    : in std_logic := '0'; -- clk.clk
		rst : in std_logic := '0';  -- rst.reset_n
		pio_0 : out std_logic_vector(7 downto 0);
		pio_1 : in std_logic--_vector(4 downto 0)
	);
end entity Lab1;



architecture arch of Lab1 is

    component Lab1_qsys is
        port (
            clk_clk     : in std_logic := 'X'; -- clk
            rst_reset_n : in std_logic := 'X';  -- reset_n
				pio_0_export : out std_logic_vector(7 downto 0);--export
				pio_1_export : in std_logic--_vector(4 downto 0)
        );
    end component Lab1_qsys;
	 
begin
    u0 : Lab1_qsys
        port map (
            clk_clk     => clk,     -- clk.clk
            rst_reset_n => rst,  -- rst.reset_n
				pio_0_export => pio_0,  -- pio_0.export
				pio_1_export => pio_1  -- pio_1.export
        );
end arch;