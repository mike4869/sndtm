function poisson(n)
for k = 1:10
    poissoned = poissrnd(100,1,n);
    name = strcat('pss', num2str(n), '_' ,char(dec2bin(k)),'.dat');
    dlmwrite(name, poissoned);
end