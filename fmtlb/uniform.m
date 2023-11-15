function uniform(n)
for k = 1:10
    Uni = 100*rand(1,n);
    name = strcat('un', num2str(n), '_' ,char(dec2bin(k)),'.dat');
    dlmwrite(name, Uni);
end