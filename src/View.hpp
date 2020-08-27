#ifndef VIEW_H 
#define VIEW_H

/**
 * A static class for drawing the simulation and other UI 
 */
class View {
    public:
        static void draw();

        // Calculate true frame rate
        // Stores the number of frames in the current second
        static long frame_no;
        static long last_frame_no;      // Number of frames when last recorded fps
        static int last_frame_rate;     // Last recorded FPS
        static int curr_frame_time;     // The second we are currently tracking

};


#endif
