import tkinter as tk
import serial

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.master.title("HC-06 Control")
        self.pack(padx=10, pady=10)
        self.create_widgets()

        self.ser = None
        self.toggle_state = tk.BooleanVar(value=False)

    def create_widgets(self):
        # Header
        self.header_label = tk.Label(self, text="BEACON", font=("Helvetica", 24, "bold"), fg="#BA2A2C")
        self.header_label.grid(row=0, columnspan=2, pady=(0, 20))

        # Port
        self.port_label = tk.Label(self, text="Port:")
        self.port_label.grid(row=0, column=0, sticky="w", pady=(50, 5))
        
        self.port_entry = tk.Entry(self, width=20)
        self.port_entry.insert(tk.END, "/dev/tty.HC-06-DevB")
        self.port_entry.grid(row=0, column=1, pady=(50, 5))

        # Baud rate
        self.baud_label = tk.Label(self, text="Baud rate:")
        self.baud_label.grid(row=1, column=0, sticky="w", pady=(0, 5))

        self.baud_entry = tk.Entry(self, width=20)
        self.baud_entry.insert(tk.END, "9600")
        self.baud_entry.grid(row=1, column=1, pady=(0, 5))

        # Connect
        self.connect_button = tk.Button(self, text="Connect", command=self.connect, width=10)
        self.connect_button.grid(row=2, column=0, pady=(0, 5))
        
        # Disconnect
        self.disconnect_button = tk.Button(self, text="Disconnect", command=self.disconnect, width=10)
        self.disconnect_button.grid(row=4, column=1, pady=(0, 5))

        # Value to send
        self.send_label = tk.Label(self, text="Value to send:")
        self.send_label.grid(row=3, column=0, sticky="w", pady=(0, 5))

        self.value_entry = tk.Entry(self, width=20)
        self.value_entry.grid(row=3, column=1, pady=(0, 5))

        # Send
        self.send_button = tk.Button(self, text="Send", command=self.send, width=10)
        self.send_button.grid(row=4, column=0, pady=(0, 5))

        # Status
        self.status_label = tk.Label(self, text="Not connected", fg="gray50")
        self.status_label.grid(row=5, columnspan=2)

        # Toggle switch
        self.toggle_label = tk.Label(self, text="Toggle switch:")
        self.toggle_label.grid(row=6, column=0, sticky="w", pady=(0, 5))

        self.toggle_button = tk.Button(self, text="Off", command=self.toggle, width=10)
        self.toggle_button.grid(row=6, column=1, pady=(0, 5))
        
    def connect(self):
        port = self.port_entry.get()
        baud_rate = self.baud_entry.get()
        try:
            self.ser = serial.Serial(port, baud_rate)
            self.status_label.config(text=f"Connected to {port} at {baud_rate} baud", fg="green")
        except:
            self.status_label.config(text="Connection failed", fg="red")

    def send(self):
        if self.ser:
            val = self.value_entry.get()
            print(f"Sending value: {val}")  # Print the value to the console
            self.ser.write(val.encode())
            self.status_label.config(text=f"Sent: {val}", fg="blue")
        else:
            self.status_label.config(text="Not connected", fg="red")
            print("Not connected")

    def disconnect(self):
        if self.ser:
            self.ser.close()
            self.ser = None
            self.status_label.config(text="Disconnected", fg="gray50")
        else:
            self.status_label.config(text="Not connected", fg="red")

    def toggle(self):
        if self.toggle_state:
            # Turn off toggle switch
            self.toggle_state = False
            self.toggle_button.config(text="Off")
            self.status_label.config(text="Toggle switch turned off", fg="red")
            value = 'L'
        else:
            # Turn on toggle switch
            self.toggle_state = True
            self.toggle_button.config(text="On")
            self.status_label.config(text="Toggle switch turned on", fg="green")
            value = 'H'
        
        # Send value
        if self.ser:
            self.ser.write(value.encode())
            self.status_label.config(text=f"Sent: {value}", fg="blue")
            print(f"Sent: {value}")
        else:
            self.status_label.config(text="Not connected", fg="red")
            print("Not connected")
            
root = tk.Tk()
app = Application(master=root)
app.mainloop()
