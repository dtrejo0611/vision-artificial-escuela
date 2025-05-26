function f2 = Canal(opcion, f0)
%Para seleccionar el canal dentro de todos los sistemas solo se debe
%colocar la letra con la que inicia el nombre del canal, por ejemplo r para
%el componente rojo de rgb, para la I en el sistema YIQ se coloca o y para
% la y del sistema cmy se coloca yell.

hsv_img = rgb2hsv(f0);

switch lower(opcion)
    case 'r'
        f2 = f0(:,:,1);
    case 'g'
        f2 = f0(:,:,2);
    case 'b'
        f2 = f0(:,:,3);
    case 'c'
        f2 = 255-f0(:,:,1);
    case 'm'
        f2 = 255-f0(:,:,2);
    case 'yell'
        f2 = 255-f0(:,:,3);
    case 'h'
        f2 = hsv_img(:,:,1);
    case 's'
        f2 = hsv_img(:,:,2);
    case 'v'
        f2 = hsv_img(:,:,3);
    case 'i'
        f2 = (f0(:,:,1) + f0(:,:,2) + f0(:,:,3)) / 3;
    case 'y'
        f2 = 0.299*double(f0(:,:,1))+0.587*double(f0(:,:,2))+0.114*double(f0(:,:,3));
    case 'o'
        f2 = 0.595716*double(f0(:,:,1))-0.274453*double(f0(:,:,2))-0.32126*double(f0(:,:,3));
    case 'q'
        f2 = 0.211456*double(f0(:,:,1))-0.522591*double(f0(:,:,2))+0.311135*double(f0(:,:,3));
    otherwise
        f2 = f0(:,:,1);

f2 = uint8(f2);
end