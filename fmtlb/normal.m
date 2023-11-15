function normal(n)
for k = 1:10
    norm = 100*randn(1,n);
    name = strcat('no', num2str(n), '_' ,char(dec2bin(k)),'.dat');
    dlmwrite(name, norm);
end