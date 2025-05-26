function f3 = Correccion(opcion, f0)
%Para seleccionar el canal dentro de todos los sistemas solo se debe
%colocar la letra con la que inicia el nombre del canal, por ejemplo c para
%cuadrado  y para potencia inversa pi

y = zeros(1,256);
f3 = zeros(size(f0));
[filas, columnas, capas] = size(f0);

switch lower(opcion)
    case 'i'
        f3 = f0;
    case 'c'
        for n=0:255
            y(1,n+1)=255*n^2/255^2;
        end
        for i=1:filas
            for j=1:columnas
                VP = f0(i, j, 1);
                f3(i, j, 1) = y(1,VP+1); 
            end
        end
    case 'r'
        for n=0:255
            y(1,n+1)=255*sqrt(n)/sqrt(255);
        end
        for i=1:filas
            for j=1:columnas
                VP = f0(i, j, 1);
                f3(i, j, 1) = y(1,VP+1); 
            end
        end
    case 'l'
        for n=0:255
            y(1,n+1)=255*log(n)/log(255);
        end
        for i=1:filas
            for j=1:columnas
                VP = f0(i, j, 1);
                f3(i, j, 1) = y(1,VP+1); 
            end
        end
    case 'e'
        c = input('Ingrese el valor de c: ');
        for n=0:255
            y(1,n+1)=255*exp(n/c)/exp(255/c);
        end
        for i=1:filas
            for j=1:columnas
                VP = f0(i, j, 1);
                f3(i, j, 1) = y(1,VP+1); 
            end
        end
    case 'p'
        p = input('Ingrese el valor de p: ');
        for n=0:255
            y(1,n+1)=255*(n^p)/(255^p);
        end
        for i=1:filas
            for j=1:columnas
                VP = f0(i, j, 1);
                f3(i, j, 1) = y(1,VP+1); 
            end
        end
    case 'pi'
        p = input('Ingrese el valor de p: ');
        for n=0:255
            y(1,n+1)=255*(n^(1/p))/(255^(1/p));
        end
        for i=1:filas
            for j=1:columnas
                VP = f0(i, j, 1);
                f3(i, j, 1) = y(1,VP+1); 
            end
        end
    otherwise
        f3 = f0;
end
f3 = uint8(f3);
end