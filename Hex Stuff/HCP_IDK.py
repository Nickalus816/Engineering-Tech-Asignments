#HCP_IDK
#Nickalus Lowrey
#Version 00.01.000

import tkinter as tk
from tkinter import filedialog, colorchooser
from PIL import Image, ImageTk
import numpy as np

class PicturePickerWithPalette:
    def __init__(self, root):
        self.root = root
        self.root.title("Picture Picker with Color Palette")
        self.root.geometry("800x600")

        # Variables
        self.image = None
        self.photo = None
        self.picked_colors = []  # Store picked colors
        self.max_palette_colors = 16  # Maximum colors in palette

        # Create frames
        self.left_frame = tk.Frame(root)
        self.left_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=10, pady=10)

        self.right_frame = tk.Frame(root)
        self.right_frame.pack(side=tk.RIGHT, fill=tk.BOTH, padx=10, pady=10)

        # Image display area
        self.canvas = tk.Canvas(self.left_frame, bg="lightgray")
        self.canvas.pack(fill=tk.BOTH, expand=True)
        self.canvas.bind("<Button-1>", self.pick_color)

        # Button to load image
        self.load_button = tk.Button(self.right_frame, text="Load Image", command=self.load_image)
        self.load_button.pack(pady=10)

        # Color info display
        self.color_info_frame = tk.Frame(self.right_frame)
        self.color_info_frame.pack(pady=10)

        tk.Label(self.color_info_frame, text="Selected Color:").grid(row=0, column=0, sticky="w")
        self.selected_color_display = tk.Frame(self.color_info_frame, width=50, height=30, bg="#FFFFFF", borderwidth=2, relief="solid")
        self.selected_color_display.grid(row=0, column=1, padx=10)

        self.color_hex_label = tk.Label(self.color_info_frame, text="Hex: #FFFFFF")
        self.color_hex_label.grid(row=1, column=0, columnspan=2, sticky="w", pady=5)

        self.color_rgb_label = tk.Label(self.color_info_frame, text="RGB: (255, 255, 255)")
        self.color_rgb_label.grid(row=2, column=0, columnspan=2, sticky="w")

        # Color palette section
        tk.Label(self.right_frame, text="Color Palette:", font=("Arial", 12, "bold")).pack(anchor="w", pady=(20, 10))

        # Frame for color palette
        self.palette_frame = tk.Frame(self.right_frame)
        self.palette_frame.pack(fill="x")

        # Button to add current color to palette
        self.add_to_palette_button = tk.Button(self.right_frame, text="Add to Palette", command=self.add_to_palette)
        self.add_to_palette_button.pack(pady=10)

        # Button to clear palette
        self.clear_palette_button = tk.Button(self.right_frame, text="Clear Palette", command=self.clear_palette)
        self.clear_palette_button.pack(pady=5)

        # Initialize empty palette
        self.update_palette_display()

    def load_image(self):
        file_path = filedialog.askopenfilename(
            filetypes=[("Image files", "*.jpg *.jpeg *.png *.bmp *.gif")]
        )

        if file_path:
            # Open and display the image
            self.image = Image.open(file_path)

            # Resize image to fit canvas while maintaining aspect ratio
            canvas_width = self.canvas.winfo_width()
            canvas_height = self.canvas.winfo_height()

            # Ensure we have valid dimensions
            if canvas_width <= 1:
                canvas_width = 500
            if canvas_height <= 1:
                canvas_height = 400

            # Calculate new dimensions
            img_width, img_height = self.image.size
            ratio = min(canvas_width/img_width, canvas_height/img_height)
            new_width = int(img_width * ratio)
            new_height = int(img_height * ratio)

            # Resize and display
            self.image = self.image.resize((new_width, new_height), Image.LANCZOS)
            self.photo = ImageTk.PhotoImage(self.image)

            # Clear canvas and display image
            self.canvas.delete("all")
            self.canvas.create_image(canvas_width/2, canvas_height/2, anchor="center", image=self.photo)
            self.canvas.config(scrollregion=self.canvas.bbox("all"))

    def pick_color(self, event):
        if self.image:
            # Convert canvas coordinates to image coordinates
            canvas_width = self.canvas.winfo_width()
            canvas_height = self.canvas.winfo_height()
            img_width, img_height = self.image.size

            # Calculate the offset if image is centered
            x_offset = (canvas_width - img_width) / 2
            y_offset = (canvas_height - img_height) / 2

            # Get x, y relative to the image
            x = int(event.x - x_offset)
            y = int(event.y - y_offset)

            # Check if click is within image bounds
            if 0 <= x < img_width and 0 <= y < img_height:
                # Get the pixel color
                rgb = self.image.getpixel((x, y))

                # If image has alpha channel, ignore it
                if len(rgb) > 3:
                    rgb = rgb[:3]

                # Update color display
                self.update_selected_color(rgb)

    def update_selected_color(self, rgb):
        # Create hex color string
        hex_color = "#{:02x}{:02x}{:02x}".format(*rgb)

        # Update display
        self.selected_color_display.config(bg=hex_color)
        self.color_hex_label.config(text=f"Hex: {hex_color}")
        self.color_rgb_label.config(text=f"RGB: {rgb}")

    def add_to_palette(self):
        # Get current color
        bg_color = self.selected_color_display.cget("bg")

        # Don't add if it's the default color
        if bg_color == "#FFFFFF" and not self.picked_colors:
            return

        # Add to palette if not already there
        if bg_color not in self.picked_colors:
            self.picked_colors.append(bg_color)

            # Limit palette size
            if len(self.picked_colors) > self.max_palette_colors:
                self.picked_colors.pop(0)  # Remove oldest color

            # Update palette display
            self.update_palette_display()

    def update_palette_display(self):
        # Clear existing palette
        for widget in self.palette_frame.winfo_children():
            widget.destroy()

        # Create color swatches for palette
        for i, color in enumerate(self.picked_colors):
            swatch = tk.Frame(self.palette_frame, width=30, height=30, bg=color, borderwidth=1, relief="solid")
            swatch.grid(row=i//8, column=i%8, padx=3, pady=3)

            # Make the swatch clickable to select color
            swatch.bind("<Button-1>", lambda e, c=color: self.select_palette_color(c))

            # Make swatches non-resizable
            swatch.pack_propagate(False)

    def select_palette_color(self, color):
        # Convert hex to RGB
        r = int(color[1:3], 16)
        g = int(color[3:5], 16)
        b = int(color[5:7], 16)

        # Update selected color
        self.update_selected_color((r, g, b))

    def clear_palette(self):
        self.picked_colors = []
        self.update_palette_display()

# Create the application
if __name__ == "__main__":
    root = tk.Tk()
    app = PicturePickerWithPalette(root)
    root.mainloop()