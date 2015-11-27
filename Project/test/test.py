#! /usr/bin/env python3

import serial

if __name__ == "__main__":
    data_buf = []
    wrong_format_time = 0
    
    range_max = 1000
    
    serial_port = "/dev/ttyUSB0"
    serial_baud = 115200
    se = serial.Serial(serial_port, serial_baud)
    
    for i in range(0,  range_max):
        try:
            str_buf = se.readline().decode("ascii")
        except UnicodeDecodeError:
            continue
            
        # print("Received data:%s" % str_buf)
        
        try:
            list_buf = str_buf.split(",")
            if len(list_buf) == 3:
                try:
                    for i in range(0,  3):
                            list_buf[i] = float(list_buf[i])
                except ValueError:
                    print("Value error")
                    continue;
                data_buf.append(list_buf)
            else:
                print("\n")
                print("\"%s\"" % list_buf)
                print("Wrong number of data: %d" % len(list_buf))
                print("Tring again...")
                print("\n")
                wrong_format_time += 1
                if wrong_format_time > 3:
                    print("\nCannot get right data, exiting.\n")
                    exit(-1)
        except:
            exit(-2)
    
    print(data_buf)
