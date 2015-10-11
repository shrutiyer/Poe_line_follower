function res = changeSpeed(speed)

s = serial('COM5'); %Setiing the Serial COM
set(s, 'BaudRate', 9600); %Setting the byte rate
fopen(s);

%Using try-catch to catch the error and close the port
    try
        for i = 1:200
            fprintf(s,speed);
        end
        fclose(s);
        delete(s);
        clear s
    catch
        %Catches the error and makes sure that the serial port is closed
        fclose(s);
        delete(s);
        clear s
    end 
end