extern crate nthash;

use nthash::{f, nthash, r};
use std::env;

fn main() {
    let seq = env::args().nth(1).unwrap();
    println!(
        "NTC64 0x{:0>16x}",
        nthash(seq.as_bytes(), seq.len() as u8)[0]
    );
    println!("fhVal 0x{:0>16x}", f(seq.as_bytes(), 0, seq.len() as u32));
    println!("rhVal 0x{:0>16x}", r(seq.as_bytes(), 0, seq.len() as u32));
}
