function chisqrd(n)
for k = 1:10
    chs = chi2rnd(6, [1,n]);
    name = strcat('chs', num2str(n), '_' ,char(dec2bin(k)),'.dat');
    dlmwrite(name, chs);
end