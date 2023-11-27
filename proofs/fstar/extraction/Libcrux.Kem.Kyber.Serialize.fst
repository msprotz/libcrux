module Libcrux.Kem.Kyber.Serialize
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

let compress_then_serialize_10_
      (v_OUT_LEN: usize)
      (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : FStar.HyperStack.ST.St (t_Array u8 v_OUT_LEN) =
  let serialized:t_Array u8 v_OUT_LEN = Rust_primitives.Hax.repeat 0uy v_OUT_LEN in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len (Rust_primitives.unsize re.Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              <:
              t_Slice i32)
          <:
          usize) /!
        sz 4
        <:
        usize)
      (fun i ->
          let i:usize = i in
          let coefficient1:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 10uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 4 <: usize) +! sz 0
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient2:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 10uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 4 <: usize) +! sz 1
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient3:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 10uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 4 <: usize) +! sz 2
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient4:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 10uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 4 <: usize) +! sz 3
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              (sz 5 *! i <: usize)
              (cast (coefficient1 &. 255l <: i32) <: u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 5 *! i <: usize) +! sz 1 <: usize)
              (((cast (coefficient2 &. 63l <: i32) <: u8) <<! 2l <: u8) |.
                (cast ((coefficient1 >>! 8l <: i32) &. 3l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 5 *! i <: usize) +! sz 2 <: usize)
              (((cast (coefficient3 &. 15l <: i32) <: u8) <<! 4l <: u8) |.
                (cast ((coefficient2 >>! 6l <: i32) &. 15l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 5 *! i <: usize) +! sz 3 <: usize)
              (((cast (coefficient4 &. 3l <: i32) <: u8) <<! 6l <: u8) |.
                (cast ((coefficient3 >>! 4l <: i32) &. 63l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 5 *! i <: usize) +! sz 4 <: usize)
              (cast ((coefficient4 >>! 2l <: i32) &. 255l <: i32) <: u8)
          in
          ())
  in
  serialized

let compress_then_serialize_11_
      (v_OUT_LEN: usize)
      (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : FStar.HyperStack.ST.St (t_Array u8 v_OUT_LEN) =
  let serialized:t_Array u8 v_OUT_LEN = Rust_primitives.Hax.repeat 0uy v_OUT_LEN in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len (Rust_primitives.unsize re.Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              <:
              t_Slice i32)
          <:
          usize) /!
        sz 8
        <:
        usize)
      (fun i ->
          let i:usize = i in
          let coefficient1:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 11uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +! sz 0
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient2:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 11uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +! sz 1
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient3:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 11uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +! sz 2
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient4:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 11uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +! sz 3
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient5:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 11uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +! sz 4
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient6:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 11uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +! sz 5
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient7:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 11uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +! sz 6
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let coefficient8:i32 =
            Libcrux.Kem.Kyber.Compress.compress_q 11uy
              (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +! sz 7
                      <:
                      usize ]
                    <:
                    i32)
                <:
                u16)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              (sz 11 *! i <: usize)
              (cast (coefficient1 <: i32) <: u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 1 <: usize)
              (((cast (coefficient2 &. 31l <: i32) <: u8) <<! 3l <: u8) |.
                (cast (coefficient1 >>! 8l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 2 <: usize)
              (((cast (coefficient3 &. 3l <: i32) <: u8) <<! 6l <: u8) |.
                (cast (coefficient2 >>! 5l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 3 <: usize)
              (cast ((coefficient3 >>! 2l <: i32) &. 255l <: i32) <: u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 4 <: usize)
              (((cast (coefficient4 &. 127l <: i32) <: u8) <<! 1l <: u8) |.
                (cast (coefficient3 >>! 10l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 5 <: usize)
              (((cast (coefficient5 &. 15l <: i32) <: u8) <<! 4l <: u8) |.
                (cast (coefficient4 >>! 7l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 6 <: usize)
              (((cast (coefficient6 &. 1l <: i32) <: u8) <<! 7l <: u8) |.
                (cast (coefficient5 >>! 4l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 7 <: usize)
              (cast ((coefficient6 >>! 1l <: i32) &. 255l <: i32) <: u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 8 <: usize)
              (((cast (coefficient7 &. 63l <: i32) <: u8) <<! 2l <: u8) |.
                (cast (coefficient6 >>! 9l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 9 <: usize)
              (((cast (coefficient8 &. 7l <: i32) <: u8) <<! 5l <: u8) |.
                (cast (coefficient7 >>! 6l <: i32) <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 11 *! i <: usize) +! sz 10 <: usize)
              (cast (coefficient8 >>! 3l <: i32) <: u8)
          in
          ())
  in
  serialized

let compress_then_serialize_4_
      (v_OUT_LEN: usize)
      (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : FStar.HyperStack.ST.St (t_Array u8 v_OUT_LEN) =
  let serialized:t_Array u8 v_OUT_LEN = Rust_primitives.Hax.repeat 0uy v_OUT_LEN in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len (Rust_primitives.unsize re.Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              <:
              t_Slice i32)
          <:
          usize) /!
        sz 2
        <:
        usize)
      (fun i ->
          let i:usize = i in
          let coefficient1:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 4uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 2 <: usize) +!
                          sz 0
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let coefficient2:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 4uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 2 <: usize) +!
                          sz 1
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              i
              ((coefficient2 <<! 4l <: u8) |. coefficient1 <: u8)
          in
          ())
  in
  serialized

let compress_then_serialize_5_
      (v_OUT_LEN: usize)
      (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : FStar.HyperStack.ST.St (t_Array u8 v_OUT_LEN) =
  let serialized:t_Array u8 v_OUT_LEN = Rust_primitives.Hax.repeat 0uy v_OUT_LEN in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len (Rust_primitives.unsize re.Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              <:
              t_Slice i32)
          <:
          usize) /!
        sz 8
        <:
        usize)
      (fun i ->
          let i:usize = i in
          let coefficient1:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 5uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +!
                          sz 0
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let coefficient2:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 5uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +!
                          sz 1
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let coefficient3:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 5uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +!
                          sz 2
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let coefficient4:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 5uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +!
                          sz 3
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let coefficient5:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 5uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +!
                          sz 4
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let coefficient6:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 5uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +!
                          sz 5
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let coefficient7:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 5uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +!
                          sz 6
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let coefficient8:u8 =
            cast (Libcrux.Kem.Kyber.Compress.compress_q 5uy
                  (Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                          .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 8 <: usize) +!
                          sz 7
                          <:
                          usize ]
                        <:
                        i32)
                    <:
                    u16)
                <:
                i32)
            <:
            u8
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              (sz 5 *! i <: usize)
              (((coefficient2 &. 7uy <: u8) <<! 5l <: u8) |. coefficient1 <: u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 5 *! i <: usize) +! sz 1 <: usize)
              ((((coefficient4 &. 1uy <: u8) <<! 7l <: u8) |. (coefficient3 <<! 2l <: u8) <: u8) |.
                (coefficient2 >>! 3l <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 5 *! i <: usize) +! sz 2 <: usize)
              (((coefficient5 &. 15uy <: u8) <<! 4l <: u8) |. (coefficient4 >>! 1l <: u8) <: u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 5 *! i <: usize) +! sz 3 <: usize)
              ((((coefficient7 &. 3uy <: u8) <<! 6l <: u8) |. (coefficient6 <<! 1l <: u8) <: u8) |.
                (coefficient5 >>! 4l <: u8)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 5 *! i <: usize) +! sz 4 <: usize)
              ((coefficient8 <<! 3l <: u8) |. (coefficient7 >>! 2l <: u8) <: u8)
          in
          ())
  in
  serialized

let compress_then_serialize_message (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : FStar.HyperStack.ST.St (t_Array u8 (sz 32)) =
  let serialized:t_Array u8 (sz 32) = Rust_primitives.Hax.repeat 0uy (sz 32) in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len (Rust_primitives.unsize re.Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              <:
              t_Slice i32)
          <:
          usize) /!
        sz 8
        <:
        usize)
      (fun index ->
          let index:usize = index in
          let i:usize = index /! sz 8 in
          let j:usize = index %! sz 8 in
          let coefficient:i32 = re.Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ index ] in
          let coefficient:u16 =
            Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative coefficient
          in
          let coefficient_compressed:i32 = Libcrux.Kem.Kyber.Compress.compress_q 1uy coefficient in
          Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
            i
            ((serialized.[ i ] <: u8) |. ((cast (coefficient_compressed <: i32) <: u8) <<! j <: u8)
              <:
              u8))
  in
  serialized

let compress_then_serialize_ring_element_u
      (v_COMPRESSION_FACTOR v_OUT_LEN: usize)
      (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : FStar.HyperStack.ST.St (t_Array u8 v_OUT_LEN) =
  let _:Prims.unit = () <: Prims.unit in
  match cast (v_COMPRESSION_FACTOR <: usize) <: u32 with
  | 10ul -> compress_then_serialize_10_ v_OUT_LEN re
  | 11ul -> compress_then_serialize_11_ v_OUT_LEN re

let compress_then_serialize_ring_element_v
      (v_COMPRESSION_FACTOR v_OUT_LEN: usize)
      (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : FStar.HyperStack.ST.St (t_Array u8 v_OUT_LEN) =
  let _:Prims.unit = () <: Prims.unit in
  match cast (v_COMPRESSION_FACTOR <: usize) <: u32 with
  | 4ul -> compress_then_serialize_4_ v_OUT_LEN re
  | 5ul -> compress_then_serialize_5_ v_OUT_LEN re

let deserialize_then_decompress_10_ (serialized: t_Slice u8)
    : FStar.HyperStack.ST.St Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let _:Prims.unit = () <: Prims.unit in
  let re:Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
    Libcrux.Kem.Kyber.Arithmetic.impl__KyberPolynomialRingElement__ZERO
  in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len serialized <: usize) /! sz 5 <: usize)
      (fun i ->
          let i:usize = i in
          let byte1:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 0 <: usize ] <: u8) <: i32
          in
          let byte2:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 1 <: usize ] <: u8) <: i32
          in
          let byte3:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 2 <: usize ] <: u8) <: i32
          in
          let byte4:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 3 <: usize ] <: u8) <: i32
          in
          let byte5:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 4 <: usize ] <: u8) <: i32
          in
          let coefficient1:i32 = ((byte2 &. 3l <: i32) <<! 8l <: i32) |. (byte1 &. 255l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              (sz 4 *! i <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 10uy coefficient1 <: i32)
          in
          let coefficient2:i32 = ((byte3 &. 15l <: i32) <<! 6l <: i32) |. (byte2 >>! 2l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 4 *! i <: usize) +! sz 1 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 10uy coefficient2 <: i32)
          in
          let coefficient3:i32 = ((byte4 &. 63l <: i32) <<! 4l <: i32) |. (byte3 >>! 4l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 4 *! i <: usize) +! sz 2 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 10uy coefficient3 <: i32)
          in
          let coefficient4:i32 = (byte5 <<! 2l <: i32) |. (byte4 >>! 6l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 4 *! i <: usize) +! sz 3 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 10uy coefficient4 <: i32)
          in
          ())
  in
  re

let deserialize_then_decompress_11_ (serialized: t_Slice u8)
    : FStar.HyperStack.ST.St Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let _:Prims.unit = () <: Prims.unit in
  let re:Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
    Libcrux.Kem.Kyber.Arithmetic.impl__KyberPolynomialRingElement__ZERO
  in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len serialized <: usize) /! sz 11 <: usize)
      (fun i ->
          let i:usize = i in
          let byte1:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 0 <: usize ] <: u8) <: i32
          in
          let byte2:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 1 <: usize ] <: u8) <: i32
          in
          let byte3:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 2 <: usize ] <: u8) <: i32
          in
          let byte4:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 3 <: usize ] <: u8) <: i32
          in
          let byte5:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 4 <: usize ] <: u8) <: i32
          in
          let byte6:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 5 <: usize ] <: u8) <: i32
          in
          let byte7:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 6 <: usize ] <: u8) <: i32
          in
          let byte8:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 7 <: usize ] <: u8) <: i32
          in
          let byte9:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 8 <: usize ] <: u8) <: i32
          in
          let byte10:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 9 <: usize ] <: u8) <: i32
          in
          let byte11:i32 =
            cast (serialized.[ (i *! sz 11 <: usize) +! sz 10 <: usize ] <: u8) <: i32
          in
          let coefficient1:i32 = ((byte2 &. 7l <: i32) <<! 8l <: i32) |. byte1 in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              (sz 8 *! i <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 11uy coefficient1 <: i32)
          in
          let coefficient2:i32 = ((byte3 &. 63l <: i32) <<! 5l <: i32) |. (byte2 >>! 3l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 1 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 11uy coefficient2 <: i32)
          in
          let coefficient3:i32 =
            (((byte5 &. 1l <: i32) <<! 10l <: i32) |. (byte4 <<! 2l <: i32) <: i32) |.
            (byte3 >>! 6l <: i32)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 2 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 11uy coefficient3 <: i32)
          in
          let coefficient4:i32 = ((byte6 &. 15l <: i32) <<! 7l <: i32) |. (byte5 >>! 1l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 3 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 11uy coefficient4 <: i32)
          in
          let coefficient5:i32 = ((byte7 &. 127l <: i32) <<! 4l <: i32) |. (byte6 >>! 4l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 4 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 11uy coefficient5 <: i32)
          in
          let coefficient6:i32 =
            (((byte9 &. 3l <: i32) <<! 9l <: i32) |. (byte8 <<! 1l <: i32) <: i32) |.
            (byte7 >>! 7l <: i32)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 5 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 11uy coefficient6 <: i32)
          in
          let coefficient7:i32 = ((byte10 &. 31l <: i32) <<! 6l <: i32) |. (byte9 >>! 2l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 6 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 11uy coefficient7 <: i32)
          in
          let coefficient8:i32 = (byte11 <<! 3l <: i32) |. (byte10 >>! 5l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 7 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 11uy coefficient8 <: i32)
          in
          ())
  in
  re

let deserialize_then_decompress_4_ (serialized: t_Slice u8)
    : FStar.HyperStack.ST.St Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let _:Prims.unit = () <: Prims.unit in
  let re:Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
    Libcrux.Kem.Kyber.Arithmetic.impl__KyberPolynomialRingElement__ZERO
  in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      (Core.Slice.impl__len serialized <: usize)
      (fun i ->
          let i:usize = i in
          let byte:u8 = serialized.[ i ] in
          let coefficient1:i32 = cast (byte &. 15uy <: u8) <: i32 in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              (sz 2 *! i <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 4uy coefficient1 <: i32)
          in
          let coefficient2:i32 = cast ((byte >>! 4l <: u8) &. 15uy <: u8) <: i32 in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 2 *! i <: usize) +! sz 1 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 4uy coefficient2 <: i32)
          in
          ())
  in
  re

let deserialize_then_decompress_5_ (serialized: t_Slice u8)
    : FStar.HyperStack.ST.St Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let _:Prims.unit = () <: Prims.unit in
  let re:Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
    Libcrux.Kem.Kyber.Arithmetic.impl__KyberPolynomialRingElement__ZERO
  in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len serialized <: usize) /! sz 5 <: usize)
      (fun i ->
          let i:usize = i in
          let byte1:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 0 <: usize ] <: u8) <: i32
          in
          let byte2:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 1 <: usize ] <: u8) <: i32
          in
          let byte3:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 2 <: usize ] <: u8) <: i32
          in
          let byte4:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 3 <: usize ] <: u8) <: i32
          in
          let byte5:i32 =
            cast (serialized.[ (i *! sz 5 <: usize) +! sz 4 <: usize ] <: u8) <: i32
          in
          let coefficient1:i32 = byte1 &. 31l in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              (sz 8 *! i <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 5uy coefficient1 <: i32)
          in
          let coefficient2:i32 = ((byte2 &. 3l <: i32) <<! 3l <: i32) |. (byte1 >>! 5l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 1 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 5uy coefficient2 <: i32)
          in
          let coefficient3:i32 = (byte2 >>! 2l <: i32) &. 31l in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 2 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 5uy coefficient3 <: i32)
          in
          let coefficient4:i32 = ((byte3 &. 15l <: i32) <<! 1l <: i32) |. (byte2 >>! 7l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 3 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 5uy coefficient4 <: i32)
          in
          let coefficient5:i32 = ((byte4 &. 1l <: i32) <<! 4l <: i32) |. (byte3 >>! 4l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 4 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 5uy coefficient5 <: i32)
          in
          let coefficient6:i32 = (byte4 >>! 1l <: i32) &. 31l in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 5 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 5uy coefficient6 <: i32)
          in
          let coefficient7:i32 = ((byte5 &. 7l <: i32) <<! 2l <: i32) |. (byte4 >>! 6l <: i32) in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 6 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 5uy coefficient7 <: i32)
          in
          let coefficient8:i32 = byte5 >>! 3l in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 8 *! i <: usize) +! sz 7 <: usize)
              (Libcrux.Kem.Kyber.Compress.decompress_q 5uy coefficient8 <: i32)
          in
          ())
  in
  re

let deserialize_then_decompress_message (serialized: t_Array u8 (sz 32))
    : FStar.HyperStack.ST.St Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let re:Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
    Libcrux.Kem.Kyber.Arithmetic.impl__KyberPolynomialRingElement__ZERO
  in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      (Core.Slice.impl__len (Rust_primitives.unsize serialized <: t_Slice u8) <: usize)
      (fun i ->
          let i:usize = i in
          let byte:u8 = serialized.[ i ] in
          Rust_primitives.f_for_loop (sz 0)
            (sz 8)
            (fun j ->
                let j:usize = j in
                let coefficient_compressed:i32 = cast ((byte >>! j <: u8) &. 1uy <: u8) <: i32 in
                let _:Prims.unit =
                  Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                      .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
                    ((sz 8 *! i <: usize) +! j <: usize)
                    (Libcrux.Kem.Kyber.Compress.decompress_q 1uy coefficient_compressed <: i32)
                in
                ()))
  in
  re

let deserialize_then_decompress_ring_element_u
      (v_COMPRESSION_FACTOR: usize)
      (serialized: t_Slice u8)
    : FStar.HyperStack.ST.St Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let _:Prims.unit = () <: Prims.unit in
  match cast (v_COMPRESSION_FACTOR <: usize) <: u32 with
  | 10ul -> deserialize_then_decompress_10_ serialized
  | 11ul -> deserialize_then_decompress_11_ serialized

let deserialize_then_decompress_ring_element_v
      (v_COMPRESSION_FACTOR: usize)
      (serialized: t_Slice u8)
    : FStar.HyperStack.ST.St Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let _:Prims.unit = () <: Prims.unit in
  match cast (v_COMPRESSION_FACTOR <: usize) <: u32 with
  | 4ul -> deserialize_then_decompress_4_ serialized
  | 5ul -> deserialize_then_decompress_5_ serialized

let deserialize_to_uncompressed_ring_element (serialized: t_Slice u8)
    : FStar.HyperStack.ST.St Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let _:Prims.unit = () <: Prims.unit in
  let re:Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
    Libcrux.Kem.Kyber.Arithmetic.impl__KyberPolynomialRingElement__ZERO
  in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len serialized <: usize) /! sz 3 <: usize)
      (fun i ->
          let i:usize = i in
          let byte1:i32 =
            cast (serialized.[ (i *! sz 3 <: usize) +! sz 0 <: usize ] <: u8) <: i32
          in
          let byte2:i32 =
            cast (serialized.[ (i *! sz 3 <: usize) +! sz 1 <: usize ] <: u8) <: i32
          in
          let byte3:i32 =
            cast (serialized.[ (i *! sz 3 <: usize) +! sz 2 <: usize ] <: u8) <: i32
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              (sz 2 *! i <: usize)
              (((byte2 &. 15l <: i32) <<! 8l <: i32) |. (byte1 &. 255l <: i32) <: i32)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize re
                .Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              ((sz 2 *! i <: usize) +! sz 1 <: usize)
              ((byte3 <<! 4l <: i32) |. ((byte2 >>! 4l <: i32) &. 15l <: i32) <: i32)
          in
          ())
  in
  re

let serialize_uncompressed_ring_element
      (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : FStar.HyperStack.ST.St (t_Array u8 (sz 384)) =
  let serialized:t_Array u8 (sz 384) = Rust_primitives.Hax.repeat 0uy (sz 384) in
  let _:Prims.unit =
    Rust_primitives.f_for_loop (sz 0)
      ((Core.Slice.impl__len (Rust_primitives.unsize re.Libcrux.Kem.Kyber.Arithmetic.f_coefficients
              <:
              t_Slice i32)
          <:
          usize) /!
        sz 2
        <:
        usize)
      (fun i ->
          let i:usize = i in
          let coefficient1:u16 =
            Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                  .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 2 <: usize) +! sz 0
                  <:
                  usize ]
                <:
                i32)
          in
          let coefficient2:u16 =
            Libcrux.Kem.Kyber.Arithmetic.to_unsigned_representative (re
                  .Libcrux.Kem.Kyber.Arithmetic.f_coefficients.[ (i *! sz 2 <: usize) +! sz 1
                  <:
                  usize ]
                <:
                i32)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              (sz 3 *! i <: usize)
              (cast (coefficient1 &. 255us <: u16) <: u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 3 *! i <: usize) +! sz 1 <: usize)
              (cast ((coefficient1 >>! 8l <: u16) |. ((coefficient2 &. 15us <: u16) <<! 4l <: u16)
                    <:
                    u16)
                <:
                u8)
          in
          let _:Prims.unit =
            Rust_primitives.Hax.Monomorphized_update_at.update_array_at_usize serialized
              ((sz 3 *! i <: usize) +! sz 2 <: usize)
              (cast ((coefficient2 >>! 4l <: u16) &. 255us <: u16) <: u8)
          in
          ())
  in
  serialized


