#[allow(dead_code)]
#[allow(unused_variables)]

struct Point {
    x: i8,
    y: i8,
}

#[derive(Debug)]
struct Plant {
    name: String,
    age: u8,
}


fn main()
{
    let point: Point = Point {x: 5, y: 3};
    println!("Position is ({}, {})", point.x, point.y);

    let name = String::from("Flower");
    let age = 12;

    let flower = Plant{name, age};

    println!("\n=== Printed with debbuger ===");
    println!("{:?}", flower);

    println!("\n=== Just print the fields of the Struct ===");
    println!("Name: {}", flower.name);
    println!("Age: {}", flower.age);
}
