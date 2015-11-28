#! /usr/bin/env python3

import serial

if __name__ == "__main__":
    # acquire the data
    print("Acquiring data...")
    
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

    se.close()

    # plot

    print("Plotting....")

    import numpy as np
    import matplotlib.pyplot as plt
    
    ax_list = []
    ay_list = []
    az_list =[]
    
    for i in range(0,  len(data_buf)):
        tmp = data_buf[i]
        ax_list.append(tmp[0])
        ay_list.append(tmp[1])
        az_list.append(tmp[2])

    x = np.arange(0,  len(data_buf),  1)
    ax = np.array(ax_list)
    ay = np.array(ay_list)
    az = np.array(az_list)

    plt.plot(x,  ax,  label = "$ax$",  color = "red")
    plt.plot(x,  ay,  label = "$ay$",  color = "blue")
    plt.plot(x,  az,  label = "$az$",  color = "black")

    plt.xlabel("Time")
    plt.ylabel("$N/m^2$")

    plt.legend()
    plt.show()
