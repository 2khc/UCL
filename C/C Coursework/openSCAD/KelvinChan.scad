use <text_on.scad>
use <spiff.scad>

//%sphere(r=6);
//text_on_sphere("Engpedometer",r=6);

// Dimensions of inner pocket
INNER_WIDTH = 7;
INNER_LENGTH = 9;
INNER_HEIGHT = 1;


module case(width = INNER_WIDTH, height = INNER_HEIGHT, length = INNER_LENGTH) {
    color("Grey")
        scale([1.5, 0.5, 1])
            sphere(r = 6);
}

module plate() {
    color("White")
    intersection(){
        translate([-5,1.55,-4]){
            cube([10,1.5,8]);
        }
        translate([0,0,0]){
            rotate([0,90,0]){
                cylinder(h=10,r = 4,center=true,$fn=50);
            }
        }
       
    }
    addText("Peduino",1,[-22,10,5],[-90,0,0]);
}

module addText(text,textHeight,position,rotation) {
    color("Black")
    mirror([0,0,1])
    mirror([1,0,0])
    scale([0.2,0.3,0.3])
    translate(position)
        rotate(a=rotation) {
            linear_extrude(height = textHeight)
            write(text);
        }
    
}

   
difference(){
    union(){
        case(INNER_WIDTH, INNER_HEIGHT, INNER_LENGTH);
        plate();
    }
    translate([0,-0.5,-3.5]) {
        cube([9,1,7]);
    }
}