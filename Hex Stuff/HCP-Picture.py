#HCP-Picture
#Nickalus Lowrey
#Version 00.00.001

import tkinter as tk
from tkinter import filedialog
from PIL import Image, ImageTk
import os

class ImageColorPicker:
    def __init__(self, root):
        self.root = root
        self.root.title("Image Color Picker")
        self.root.geometry("800x600")

        # Variables
        self.image_path = None
        self.original_image = None
        self.display_image = None
        self.current_color = "#FFFFFF"  # Default white

        # Create frames
        self.top_frame = tk.Frame(root)
        self.top_frame.pack(fill=tk.X, padx=10, pady=10)

        self.image_frame = tk.Frame(root)
        self.image_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        self.color_frame = tk.Frame(root)
        self.color_frame.pack(fill=tk.X, padx=10, pady=10)

        # Top frame components
        self.load_button = tk.Button(self.top_frame, text="Load Image", command=self.load_image)
        self.load_button.pack(side=tk.LEFT, padx=5)

        self.instruction_label = tk.Label(self.top_frame, text="Click on the image to pick a color")
        self.instruction_label.pack(side=tk.LEFT, padx=20)

        # Image display
        self.canvas = tk.Canvas(self.image_frame, bg="gray")
        self.canvas.pack(fill=tk.BOTH, expand=True)
        self.canvas.bind("<Button-1>", self.pick_color)

        # Color display components
        self.color_display = tk.Label(self.color_frame, width=10, height=2, bg=self.current_color)
        self.color_display.pack(side=tk.LEFT, padx=10)

        self.hex_label = tk.Label(self.color_frame, text=f"HEX: {self.current_color}")
        self.hex_label.pack(side=tk.LEFT, padx=10)

        self.rgb_label = tk.Label(self.color_frame, text="RGB: (255, 255, 255)")
        self.rgb_label.pack(side=tk.LEFT, padx=10)

        self.copy_button = tk.Button(self.color_frame, text="Copy HEX", command=self.copy_hex)
        self.copy_button.pack(side=tk.RIGHT, padx=10)

    def load_image(self):
        self.image_path = filedialog.askopenfilename(
            title="Select Image",
            filetypes=[("Image files", "*.png *.jpg *.jpeg *.bmp *.gif")]
        )

        if self.image_path:
            # Load the image
            self.original_image = Image.open(self.image_path)
            self.update_canvas()

    def update_canvas(self):
        # Resize image to fit canvas while maintaining aspect ratio
        canvas_width = self.canvas.winfo_width()
        canvas_height = self.canvas.winfo_height()

        if canvas_width <= 1:  # Canvas not yet drawn
            self.root.update()
            canvas_width = self.canvas.winfo_width()
            canvas_height = self.canvas.winfo_height()

        img_width, img_height = self.original_image.size
        ratio = min(canvas_width/img_width, canvas_height/img_height)
        new_width = int(img_width * ratio)
        new_height = int(img_height * ratio)

        resized_image = self.original_image.resize((new_width, new_height), Image.LANCZOS)
        self.display_image = ImageTk.PhotoImage(resized_image)

        # Update canvas
        self.canvas.delete("all")
        self.canvas.create_image(
            canvas_width//2, canvas_height//2,
            image=self.display_image,
            anchor=tk.CENTER
        )

        # Store resize ratio for color picking
        self.resize_ratio = img_width / new_width

    def pick_color(self, event):
        if not self.original_image:
            return

        # Calculate position in original image
        canvas_width = self.canvas.winfo_width()
        canvas_height = self.canvas.winfo_height()
        img_width, img_height = self.display_image.width(), self.display_image.height()

        # Calculate offsets to center the image
        x_offset = (canvas_width - img_width) // 2
        y_offset = (canvas_height - img_height) // 2

        # Get click position relative to image
        x = event.x - x_offset
        y = event.y - y_offset

        # Check if click is within image bounds
        if 0 <= x < img_width and 0 <= y < img_height:
            # Convert to original image coordinates
            orig_x = int(x * self.resize_ratio)
            orig_y = int(y * self.resize_ratio)

            # Get pixel color
            r, g, b = self.original_image.getpixel((orig_x, orig_y))[:3]  # Handle alpha if present

            # Update color display
            self.current_color = f"#{r:02x}{g:02x}{b:02x}"
            self.color_display.config(bg=self.current_color)
            self.hex_label.config(text=f"HEX: {self.current_color}")
            self.rgb_label.config(text=f"RGB: ({r}, {g}, {b})")

    def copy_hex(self):
        self.root.clipboard_clear()
        self.root.clipboard_append(self.current_color)
        self.root.update()  # Required for clipboard to work

# Create the application
if __name__ == "__main__":
    root = tk.Tk()
    app = ImageColorPicker(root)

    # Add window resize handler
    def on_resize(event):
        if app.original_image:
            app.update_canvas()

    root.bind("<Configure>", on_resize)
    root.mainloop()