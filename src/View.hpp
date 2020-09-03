#ifndef VIEW_H 
#define VIEW_H

/**
 * A static class for drawing the simulation and other UI.
 * 
 * Should probably be a namespace but oh well.
 */
class View {
    public:
        static void init(int argc, char** argv);
        static void draw();

        static void reshape_callback(int w, int h);
        static void mouse_callback(int button, int state, int x , int y);
        static void motion_callback(int x, int y);

        // Calculate true frame rate
        // Stores the number of frames in the current second
        static long frame_no;
        static long last_frame_no;      // Number of frames when last recorded fps
        static int last_frame_rate;     // Last recorded FPS
        static int curr_frame_time;     // The second we are currently tracking

        // Movement/zooming around the environment
        static double zoom;
        static int drag_prev_x;
        static int drag_prev_y;
        static double translate_x;
        static double translate_y;

        static int window_width;
        static int window_height;

};


#endif
