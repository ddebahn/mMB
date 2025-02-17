// =============================================
// 01. Arduino Nano als IO-Expander
// =============================================
// <S DCC-Adresse, Vpin, PULL-UP>
// <Z DCC-Adresse, Vpin, iflag>
//
// Die nicht benutzten bitte auskommentieren
// 
// 1. Nano - Eingänge
SETUP("<S 800 800 1>"); // Vpin 800 = PIN D2 des NANO
// SETUP("<S 801 801 1>"); // Vpin 801 = PIN D3 des NANO
// SETUP("<S 802 802 1>"); // Vpin 802 = PIN D4 des NANO
// SETUP("<S 803 803 1>"); // Vpin 803 = PIN D5 des NANO
// SETUP("<S 804 804 1>"); // Vpin 804 = PIN D6 des NANO
// SETUP("<S 805 805 1>"); // Vpin 805 = PIN D7 des NANO
// SETUP("<S 806 806 1>"); // Vpin 806 = PIN D8 des NANO
// SETUP("<S 807 807 1>"); // Vpin 807 = PIN D9 des NANO
// SETUP("<S 808 808 1>"); // Vpin 808 = PIN D10 des NANO
// SETUP("<S 809 809 1>"); // Vpin 809 = PIN D11 des NANO
// SETUP("<S 810 810 1>"); // Vpin 810 = PIN D12 des NANO
// SETUP("<S 811 811 1>"); // Vpin 811 = PIN D13 des NANO
// SETUP("<S 812 812 1>"); // Vpin 812 = PIN A0 des NANO
// SETUP("<S 813 813 1>"); // Vpin 813 = PIN A1 des NANO
// SETUP("<S 814 814 1>"); // Vpin 814 = PIN A2 des NANO
// SETUP("<S 815 815 1>"); // Vpin 815 = PIN A3 des NANO
// Vpin 816 ist kein Digital Anschluß, kann somit nicht benutzt werden
// Vpin 817 ist kein Digital Anschluß, kann somit nicht benutzt werden
//
// 2. Nano  - Eingänge
SETUP("<S 818 818 1>"); // Vpin 818 = PIN D2 des NANO
// SETUP("<S 819 819 1>"); // Vpin 819 = PIN D3 des NANO
// SETUP("<S 820 820 1>"); // Vpin 820 = PIN D4 des NANO
// SETUP("<S 821 821 1>"); // Vpin 821 = PIN D5 des NANO
// SETUP("<S 822 822 1>"); // Vpin 822 = PIN D6 des NANO
// SETUP("<S 823 823 1>"); // Vpin 823 = PIN D7 des NANO
// SETUP("<S 824 824 1>"); // Vpin 824 = PIN D8 des NANO
// SETUP("<S 825 825 1>"); // Vpin 825 = PIN D9 des NANO
// SETUP("<S 826 826 1>"); // Vpin 826 = PIN D10 des NANO
// SETUP("<S 827 827 1>"); // Vpin 827 = PIN D11 des NANO
// SETUP("<S 828 828 1>"); // Vpin 828 = PIN D12 des NANO
// SETUP("<S 829 829 1>"); // Vpin 829 = PIN D13 des NANO
// SETUP("<S 830 830 1>"); // Vpin 830 = PIN A0 des NANO
// SETUP("<S 831 831 1>"); // Vpin 831 = PIN A1 des NANO
// SETUP("<S 832 832 1>"); // Vpin 832 = PIN A2 des NANO
// SETUP("<S 833 833 1>"); // Vpin 833 = PIN A3 des NANO
// Vpin 834 ist kein Digital Anschluß, kann somit nicht benutzt werden
// Vpin 835 ist kein Digital Anschluß, kann somit nicht benutzt werden
//
// 1. Nano - Ausgänge
// SETUP("<Z 800 800 0>"); // Vpin 800 = PIN D2 des NANO
SETUP("<Z 801 801 0>"); // Vpin 801 = PIN D3 des NANO
// SETUP("<Z 802 802 0>"); // Vpin 802 = PIN D4 des NANO
// SETUP("<Z 803 803 0>"); // Vpin 803 = PIN D5 des NANO
// SETUP("<Z 804 804 0>"); // Vpin 804 = PIN D6 des NANO
// SETUP("<Z 805 805 0>"); // Vpin 805 = PIN D7 des NANO
// SETUP("<Z 806 806 0>"); // Vpin 806 = PIN D8 des NANO
// SETUP("<Z 807 807 0>"); // Vpin 807 = PIN D9 des NANO
// SETUP("<Z 808 808 0>"); // Vpin 808 = PIN D10 des NANO
// SETUP("<Z 809 809 0>"); // Vpin 809 = PIN D11 des NANO
// SETUP("<Z 810 810 0>"); // Vpin 810 = PIN D12 des NANO
// SETUP("<Z 811 811 0>"); // Vpin 811 = PIN D13 des NANO
// SETUP("<Z 812 812 0>"); // Vpin 812 = PIN A0 des NANO
// SETUP("<Z 813 813 0>"); // Vpin 813 = PIN A1 des NANO
// SETUP("<Z 814 814 0>"); // Vpin 814 = PIN A2 des NANO
// SETUP("<Z 815 815 0>"); // Vpin 815 = PIN A3 des NANO
// Vpin 816 ist kein Digital Anschluß, kann somit nicht benutzt werden
// Vpin 817 ist kein Digital Anschluß, kann somit nicht benutzt werden
//
// 2. Nano  - Ausgänge
// SETUP("<Z 818 818 0>"); // Vpin 818 = PIN D2 des NANO
SETUP("<Z 819 819 0>"); // Vpin 819 = PIN D3 des NANO
// SETUP("<Z 820 820 0>"); // Vpin 820 = PIN D4 des NANO
// SETUP("<Z 821 821 0>"); // Vpin 821 = PIN D5 des NANO
// SETUP("<Z 822 822 0>"); // Vpin 822 = PIN D6 des NANO
// SETUP("<Z 823 823 0>"); // Vpin 823 = PIN D7 des NANO
// SETUP("<Z 824 824 0>"); // Vpin 824 = PIN D8 des NANO
// SETUP("<Z 825 825 0>"); // Vpin 825 = PIN D9 des NANO
// SETUP("<Z 826 826 0>"); // Vpin 826 = PIN D10 des NANO
// SETUP("<Z 827 827 0>"); // Vpin 827 = PIN D11 des NANO
// SETUP("<Z 828 828 0>"); // Vpin 828 = PIN D12 des NANO
// SETUP("<Z 829 829 0>"); // Vpin 829 = PIN D13 des NANO
// SETUP("<Z 830 830 0>"); // Vpin 830 = PIN A0 des NANO
// SETUP("<Z 831 831 0>"); // Vpin 831 = PIN A1 des NANO
// SETUP("<Z 832 832 0>"); // Vpin 832 = PIN A2 des NANO
// SETUP("<Z 833 833 0>"); // Vpin 833 = PIN A3 des NANO
// Vpin 834 ist kein Digital Anschluß, kann somit nicht benutzt werden
// Vpin 835 ist kein Digital Anschluß, kann somit nicht benutzt werden
//
// =============================================
// 02. MEGA Ein/ Ausgänge
// =============================================
// <S DCC-Adresse, Vpin, PULL-UP>
// <Z DCC-Adresse, Vpin, iflag>
// MEGA - Eingänge
SETUP("<S 24 24 1>"); // DCC-Adresse 24 = PIN 24 des MEGA
//
// MEGA - Ausgänge
SETUP("<Z 22 22 0>"); // DCC-Adresse 22 = PIN 22 des MEGA
//
// =============================================
// 03. MCP23017 Ein/ Ausgänge
// =============================================
// <S DCC-Adresse, Vpin, PULL-UP>
// <Z DCC-Adresse, Vpin, iflag>
//
// Die nicht benutzten bitte auskommentieren
//
// 1. MCP23017 - Eingänge
// SETUP("<S 196 196 1>"); // Vpin 197 = PIN A0 des MCP23017
SETUP("<S 197 197 1>"); // Vpin 197 = PIN A1 des MCP23017
// SETUP("<S 198 198 1>"); // Vpin 198 = PIN A2 des MCP23017
// SETUP("<S 199 199 1>"); // Vpin 199 = PIN A3 des MCP23017
// SETUP("<S 200 200 1>"); // Vpin 200 = PIN A4 des MCP23017
// SETUP("<S 201 201 1>"); // Vpin 201 = PIN A5 des MCP23017
// SETUP("<S 202 202 1>"); // Vpin 202 = PIN A6 des MCP23017
// SETUP("<S 203 203 1>"); // Vpin 203 = PIN A7 des MCP23017
// SETUP("<S 204 204 1>"); // Vpin 204 = PIN B0 des MCP23017
// SETUP("<S 205 205 1>"); // Vpin 205 = PIN B1 des MCP23017
// SETUP("<S 206 206 1>"); // Vpin 206 = PIN B2 des MCP23017
// SETUP("<S 207 207 1>"); // Vpin 207 = PIN B3 des MCP23017
// SETUP("<S 208 208 1>"); // Vpin 208 = PIN B4 des MCP23017
// SETUP("<S 209 209 1>"); // Vpin 209 = PIN B5 des MCP23017
// SETUP("<S 210 210 1>"); // Vpin 210 = PIN B6 des MCP23017
// SETUP("<S 211 211 1>"); // Vpin 211 = PIN B7 des MCP23017
//
// 1. MCP23017 - Ausgänge
SETUP("<Z 196 196 0>"); // Vpin 196 = PIN A0 des MCP23017
// SETUP("<Z 197 197 0>"); // Vpin 197 = PIN A1 des MCP23017
// SETUP("<Z 198 198 0>"); // Vpin 198 = PIN A2 des MCP23017
// SETUP("<Z 199 199 0>"); // Vpin 199 = PIN A3 des MCP23017
// SETUP("<Z 200 200 0>"); // Vpin 200 = PIN A4 des MCP23017
// SETUP("<Z 201 201 0>"); // Vpin 201 = PIN A5 des MCP23017
// SETUP("<Z 202 202 0>"); // Vpin 202 = PIN A6 des MCP23017
// SETUP("<Z 203 203 0>"); // Vpin 203 = PIN A7 des MCP23017
// SETUP("<Z 204 204 0>"); // Vpin 204 = PIN B0 des MCP23017
// SETUP("<Z 205 205 0>"); // Vpin 205 = PIN B1 des MCP23017
// SETUP("<Z 206 206 0>"); // Vpin 206 = PIN B2 des MCP23017
// SETUP("<Z 207 207 0>"); // Vpin 207 = PIN B3 des MCP23017
// SETUP("<Z 208 208 0>"); // Vpin 208 = PIN B4 des MCP23017
// SETUP("<Z 209 209 0>"); // Vpin 209 = PIN B5 des MCP23017
// SETUP("<Z 210 210 0>"); // Vpin 210 = PIN B6 des MCP23017
// SETUP("<Z 211 211 0>"); // Vpin 211 = PIN B7 des MCP23017
//
