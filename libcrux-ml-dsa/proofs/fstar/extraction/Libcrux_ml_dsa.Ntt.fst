module Libcrux_ml_dsa.Ntt
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

let _ =
  (* This module has implicit dependencies, here we make them explicit. *)
  (* The implicit dependencies arise from typeclasses instances. *)
  let open Libcrux_ml_dsa.Simd.Traits in
  ()

let v_ZETAS_TIMES_MONTGOMERY_R: t_Array i32 (Rust_primitives.mk_usize 256) =
  let list =
    [
      Rust_primitives.mk_i32 0; Rust_primitives.mk_i32 25847; Rust_primitives.mk_i32 (-2608894);
      Rust_primitives.mk_i32 (-518909); Rust_primitives.mk_i32 237124;
      Rust_primitives.mk_i32 (-777960); Rust_primitives.mk_i32 (-876248);
      Rust_primitives.mk_i32 466468; Rust_primitives.mk_i32 1826347; Rust_primitives.mk_i32 2353451;
      Rust_primitives.mk_i32 (-359251); Rust_primitives.mk_i32 (-2091905);
      Rust_primitives.mk_i32 3119733; Rust_primitives.mk_i32 (-2884855);
      Rust_primitives.mk_i32 3111497; Rust_primitives.mk_i32 2680103; Rust_primitives.mk_i32 2725464;
      Rust_primitives.mk_i32 1024112; Rust_primitives.mk_i32 (-1079900);
      Rust_primitives.mk_i32 3585928; Rust_primitives.mk_i32 (-549488);
      Rust_primitives.mk_i32 (-1119584); Rust_primitives.mk_i32 2619752;
      Rust_primitives.mk_i32 (-2108549); Rust_primitives.mk_i32 (-2118186);
      Rust_primitives.mk_i32 (-3859737); Rust_primitives.mk_i32 (-1399561);
      Rust_primitives.mk_i32 (-3277672); Rust_primitives.mk_i32 1757237;
      Rust_primitives.mk_i32 (-19422); Rust_primitives.mk_i32 4010497; Rust_primitives.mk_i32 280005;
      Rust_primitives.mk_i32 2706023; Rust_primitives.mk_i32 95776; Rust_primitives.mk_i32 3077325;
      Rust_primitives.mk_i32 3530437; Rust_primitives.mk_i32 (-1661693);
      Rust_primitives.mk_i32 (-3592148); Rust_primitives.mk_i32 (-2537516);
      Rust_primitives.mk_i32 3915439; Rust_primitives.mk_i32 (-3861115);
      Rust_primitives.mk_i32 (-3043716); Rust_primitives.mk_i32 3574422;
      Rust_primitives.mk_i32 (-2867647); Rust_primitives.mk_i32 3539968;
      Rust_primitives.mk_i32 (-300467); Rust_primitives.mk_i32 2348700;
      Rust_primitives.mk_i32 (-539299); Rust_primitives.mk_i32 (-1699267);
      Rust_primitives.mk_i32 (-1643818); Rust_primitives.mk_i32 3505694;
      Rust_primitives.mk_i32 (-3821735); Rust_primitives.mk_i32 3507263;
      Rust_primitives.mk_i32 (-2140649); Rust_primitives.mk_i32 (-1600420);
      Rust_primitives.mk_i32 3699596; Rust_primitives.mk_i32 811944; Rust_primitives.mk_i32 531354;
      Rust_primitives.mk_i32 954230; Rust_primitives.mk_i32 3881043; Rust_primitives.mk_i32 3900724;
      Rust_primitives.mk_i32 (-2556880); Rust_primitives.mk_i32 2071892;
      Rust_primitives.mk_i32 (-2797779); Rust_primitives.mk_i32 (-3930395);
      Rust_primitives.mk_i32 (-1528703); Rust_primitives.mk_i32 (-3677745);
      Rust_primitives.mk_i32 (-3041255); Rust_primitives.mk_i32 (-1452451);
      Rust_primitives.mk_i32 3475950; Rust_primitives.mk_i32 2176455;
      Rust_primitives.mk_i32 (-1585221); Rust_primitives.mk_i32 (-1257611);
      Rust_primitives.mk_i32 1939314; Rust_primitives.mk_i32 (-4083598);
      Rust_primitives.mk_i32 (-1000202); Rust_primitives.mk_i32 (-3190144);
      Rust_primitives.mk_i32 (-3157330); Rust_primitives.mk_i32 (-3632928);
      Rust_primitives.mk_i32 126922; Rust_primitives.mk_i32 3412210;
      Rust_primitives.mk_i32 (-983419); Rust_primitives.mk_i32 2147896;
      Rust_primitives.mk_i32 2715295; Rust_primitives.mk_i32 (-2967645);
      Rust_primitives.mk_i32 (-3693493); Rust_primitives.mk_i32 (-411027);
      Rust_primitives.mk_i32 (-2477047); Rust_primitives.mk_i32 (-671102);
      Rust_primitives.mk_i32 (-1228525); Rust_primitives.mk_i32 (-22981);
      Rust_primitives.mk_i32 (-1308169); Rust_primitives.mk_i32 (-381987);
      Rust_primitives.mk_i32 1349076; Rust_primitives.mk_i32 1852771;
      Rust_primitives.mk_i32 (-1430430); Rust_primitives.mk_i32 (-3343383);
      Rust_primitives.mk_i32 264944; Rust_primitives.mk_i32 508951; Rust_primitives.mk_i32 3097992;
      Rust_primitives.mk_i32 44288; Rust_primitives.mk_i32 (-1100098); Rust_primitives.mk_i32 904516;
      Rust_primitives.mk_i32 3958618; Rust_primitives.mk_i32 (-3724342);
      Rust_primitives.mk_i32 (-8578); Rust_primitives.mk_i32 1653064;
      Rust_primitives.mk_i32 (-3249728); Rust_primitives.mk_i32 2389356;
      Rust_primitives.mk_i32 (-210977); Rust_primitives.mk_i32 759969;
      Rust_primitives.mk_i32 (-1316856); Rust_primitives.mk_i32 189548;
      Rust_primitives.mk_i32 (-3553272); Rust_primitives.mk_i32 3159746;
      Rust_primitives.mk_i32 (-1851402); Rust_primitives.mk_i32 (-2409325);
      Rust_primitives.mk_i32 (-177440); Rust_primitives.mk_i32 1315589;
      Rust_primitives.mk_i32 1341330; Rust_primitives.mk_i32 1285669;
      Rust_primitives.mk_i32 (-1584928); Rust_primitives.mk_i32 (-812732);
      Rust_primitives.mk_i32 (-1439742); Rust_primitives.mk_i32 (-3019102);
      Rust_primitives.mk_i32 (-3881060); Rust_primitives.mk_i32 (-3628969);
      Rust_primitives.mk_i32 3839961; Rust_primitives.mk_i32 2091667; Rust_primitives.mk_i32 3407706;
      Rust_primitives.mk_i32 2316500; Rust_primitives.mk_i32 3817976;
      Rust_primitives.mk_i32 (-3342478); Rust_primitives.mk_i32 2244091;
      Rust_primitives.mk_i32 (-2446433); Rust_primitives.mk_i32 (-3562462);
      Rust_primitives.mk_i32 266997; Rust_primitives.mk_i32 2434439;
      Rust_primitives.mk_i32 (-1235728); Rust_primitives.mk_i32 3513181;
      Rust_primitives.mk_i32 (-3520352); Rust_primitives.mk_i32 (-3759364);
      Rust_primitives.mk_i32 (-1197226); Rust_primitives.mk_i32 (-3193378);
      Rust_primitives.mk_i32 900702; Rust_primitives.mk_i32 1859098; Rust_primitives.mk_i32 909542;
      Rust_primitives.mk_i32 819034; Rust_primitives.mk_i32 495491;
      Rust_primitives.mk_i32 (-1613174); Rust_primitives.mk_i32 (-43260);
      Rust_primitives.mk_i32 (-522500); Rust_primitives.mk_i32 (-655327);
      Rust_primitives.mk_i32 (-3122442); Rust_primitives.mk_i32 2031748;
      Rust_primitives.mk_i32 3207046; Rust_primitives.mk_i32 (-3556995);
      Rust_primitives.mk_i32 (-525098); Rust_primitives.mk_i32 (-768622);
      Rust_primitives.mk_i32 (-3595838); Rust_primitives.mk_i32 342297;
      Rust_primitives.mk_i32 286988; Rust_primitives.mk_i32 (-2437823);
      Rust_primitives.mk_i32 4108315; Rust_primitives.mk_i32 3437287;
      Rust_primitives.mk_i32 (-3342277); Rust_primitives.mk_i32 1735879;
      Rust_primitives.mk_i32 203044; Rust_primitives.mk_i32 2842341; Rust_primitives.mk_i32 2691481;
      Rust_primitives.mk_i32 (-2590150); Rust_primitives.mk_i32 1265009;
      Rust_primitives.mk_i32 4055324; Rust_primitives.mk_i32 1247620; Rust_primitives.mk_i32 2486353;
      Rust_primitives.mk_i32 1595974; Rust_primitives.mk_i32 (-3767016);
      Rust_primitives.mk_i32 1250494; Rust_primitives.mk_i32 2635921;
      Rust_primitives.mk_i32 (-3548272); Rust_primitives.mk_i32 (-2994039);
      Rust_primitives.mk_i32 1869119; Rust_primitives.mk_i32 1903435;
      Rust_primitives.mk_i32 (-1050970); Rust_primitives.mk_i32 (-1333058);
      Rust_primitives.mk_i32 1237275; Rust_primitives.mk_i32 (-3318210);
      Rust_primitives.mk_i32 (-1430225); Rust_primitives.mk_i32 (-451100);
      Rust_primitives.mk_i32 1312455; Rust_primitives.mk_i32 3306115;
      Rust_primitives.mk_i32 (-1962642); Rust_primitives.mk_i32 (-1279661);
      Rust_primitives.mk_i32 1917081; Rust_primitives.mk_i32 (-2546312);
      Rust_primitives.mk_i32 (-1374803); Rust_primitives.mk_i32 1500165;
      Rust_primitives.mk_i32 777191; Rust_primitives.mk_i32 2235880; Rust_primitives.mk_i32 3406031;
      Rust_primitives.mk_i32 (-542412); Rust_primitives.mk_i32 (-2831860);
      Rust_primitives.mk_i32 (-1671176); Rust_primitives.mk_i32 (-1846953);
      Rust_primitives.mk_i32 (-2584293); Rust_primitives.mk_i32 (-3724270);
      Rust_primitives.mk_i32 594136; Rust_primitives.mk_i32 (-3776993);
      Rust_primitives.mk_i32 (-2013608); Rust_primitives.mk_i32 2432395;
      Rust_primitives.mk_i32 2454455; Rust_primitives.mk_i32 (-164721);
      Rust_primitives.mk_i32 1957272; Rust_primitives.mk_i32 3369112; Rust_primitives.mk_i32 185531;
      Rust_primitives.mk_i32 (-1207385); Rust_primitives.mk_i32 (-3183426);
      Rust_primitives.mk_i32 162844; Rust_primitives.mk_i32 1616392; Rust_primitives.mk_i32 3014001;
      Rust_primitives.mk_i32 810149; Rust_primitives.mk_i32 1652634;
      Rust_primitives.mk_i32 (-3694233); Rust_primitives.mk_i32 (-1799107);
      Rust_primitives.mk_i32 (-3038916); Rust_primitives.mk_i32 3523897;
      Rust_primitives.mk_i32 3866901; Rust_primitives.mk_i32 269760; Rust_primitives.mk_i32 2213111;
      Rust_primitives.mk_i32 (-975884); Rust_primitives.mk_i32 1717735;
      Rust_primitives.mk_i32 472078; Rust_primitives.mk_i32 (-426683);
      Rust_primitives.mk_i32 1723600; Rust_primitives.mk_i32 (-1803090);
      Rust_primitives.mk_i32 1910376; Rust_primitives.mk_i32 (-1667432);
      Rust_primitives.mk_i32 (-1104333); Rust_primitives.mk_i32 (-260646);
      Rust_primitives.mk_i32 (-3833893); Rust_primitives.mk_i32 (-2939036);
      Rust_primitives.mk_i32 (-2235985); Rust_primitives.mk_i32 (-420899);
      Rust_primitives.mk_i32 (-2286327); Rust_primitives.mk_i32 183443;
      Rust_primitives.mk_i32 (-976891); Rust_primitives.mk_i32 1612842;
      Rust_primitives.mk_i32 (-3545687); Rust_primitives.mk_i32 (-554416);
      Rust_primitives.mk_i32 3919660; Rust_primitives.mk_i32 (-48306);
      Rust_primitives.mk_i32 (-1362209); Rust_primitives.mk_i32 3937738;
      Rust_primitives.mk_i32 1400424; Rust_primitives.mk_i32 (-846154);
      Rust_primitives.mk_i32 1976782
    ]
  in
  FStar.Pervasives.assert_norm (Prims.eq2 (List.Tot.length list) 256);
  Rust_primitives.Hax.array_of_list 256 list

let invert_ntt_at_layer_0_
      (#v_SIMDUnit: Type0)
      (#[FStar.Tactics.Typeclasses.tcresolve ()]
          i1:
          Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit)
      (zeta_i: usize)
      (re: Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
    : (usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
  let zeta_i:usize = zeta_i -! Rust_primitives.mk_usize 1 in
  let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
    Rust_primitives.Hax.Folds.fold_range (Rust_primitives.mk_usize 0)
      (Core.Slice.impl__len #v_SIMDUnit
          (re.Libcrux_ml_dsa.Polynomial.f_simd_units <: t_Slice v_SIMDUnit)
        <:
        usize)
      (fun temp_0_ temp_1_ ->
          let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
            temp_0_
          in
          let _:usize = temp_1_ in
          true)
      (re, zeta_i <: (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize))
      (fun temp_0_ round ->
          let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
            temp_0_
          in
          let round:usize = round in
          let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
            {
              re with
              Libcrux_ml_dsa.Polynomial.f_simd_units
              =
              Rust_primitives.Hax.Monomorphized_update_at.update_at_usize re
                  .Libcrux_ml_dsa.Polynomial.f_simd_units
                round
                (Libcrux_ml_dsa.Simd.Traits.f_invert_ntt_at_layer_0_ #v_SIMDUnit
                    #FStar.Tactics.Typeclasses.solve
                    (re.Libcrux_ml_dsa.Polynomial.f_simd_units.[ round ] <: v_SIMDUnit)
                    (v_ZETAS_TIMES_MONTGOMERY_R.[ zeta_i ] <: i32)
                    (v_ZETAS_TIMES_MONTGOMERY_R.[ zeta_i -! Rust_primitives.mk_usize 1 <: usize ]
                      <:
                      i32)
                    (v_ZETAS_TIMES_MONTGOMERY_R.[ zeta_i -! Rust_primitives.mk_usize 2 <: usize ]
                      <:
                      i32)
                    (v_ZETAS_TIMES_MONTGOMERY_R.[ zeta_i -! Rust_primitives.mk_usize 3 <: usize ]
                      <:
                      i32)
                  <:
                  v_SIMDUnit)
            }
            <:
            Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit
          in
          let zeta_i:usize = zeta_i -! Rust_primitives.mk_usize 4 in
          re, zeta_i <: (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize))
  in
  let zeta_i:usize = zeta_i +! Rust_primitives.mk_usize 1 in
  zeta_i, re <: (usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)

let invert_ntt_at_layer_1_
      (#v_SIMDUnit: Type0)
      (#[FStar.Tactics.Typeclasses.tcresolve ()]
          i1:
          Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit)
      (zeta_i: usize)
      (re: Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
    : (usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
  let zeta_i:usize = zeta_i -! Rust_primitives.mk_usize 1 in
  let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
    Rust_primitives.Hax.Folds.fold_range (Rust_primitives.mk_usize 0)
      (Rust_primitives.mk_usize 256 /! Libcrux_ml_dsa.Simd.Traits.v_COEFFICIENTS_IN_SIMD_UNIT
        <:
        usize)
      (fun temp_0_ temp_1_ ->
          let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
            temp_0_
          in
          let _:usize = temp_1_ in
          true)
      (re, zeta_i <: (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize))
      (fun temp_0_ round ->
          let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
            temp_0_
          in
          let round:usize = round in
          let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
            {
              re with
              Libcrux_ml_dsa.Polynomial.f_simd_units
              =
              Rust_primitives.Hax.Monomorphized_update_at.update_at_usize re
                  .Libcrux_ml_dsa.Polynomial.f_simd_units
                round
                (Libcrux_ml_dsa.Simd.Traits.f_invert_ntt_at_layer_1_ #v_SIMDUnit
                    #FStar.Tactics.Typeclasses.solve
                    (re.Libcrux_ml_dsa.Polynomial.f_simd_units.[ round ] <: v_SIMDUnit)
                    (v_ZETAS_TIMES_MONTGOMERY_R.[ zeta_i ] <: i32)
                    (v_ZETAS_TIMES_MONTGOMERY_R.[ zeta_i -! Rust_primitives.mk_usize 1 <: usize ]
                      <:
                      i32)
                  <:
                  v_SIMDUnit)
            }
            <:
            Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit
          in
          let zeta_i:usize = zeta_i -! Rust_primitives.mk_usize 2 in
          re, zeta_i <: (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize))
  in
  let zeta_i:usize = zeta_i +! Rust_primitives.mk_usize 1 in
  zeta_i, re <: (usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)

let invert_ntt_at_layer_2_
      (#v_SIMDUnit: Type0)
      (#[FStar.Tactics.Typeclasses.tcresolve ()]
          i1:
          Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit)
      (zeta_i: usize)
      (re: Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
    : (usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
  let (re, zeta_i), hax_temp_output:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit &
    usize) =
    Rust_primitives.Hax.Folds.fold_range (Rust_primitives.mk_usize 0)
      (Rust_primitives.mk_usize 256 /! Libcrux_ml_dsa.Simd.Traits.v_COEFFICIENTS_IN_SIMD_UNIT
        <:
        usize)
      (fun temp_0_ temp_1_ ->
          let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
            temp_0_
          in
          let _:usize = temp_1_ in
          true)
      (re, zeta_i <: (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize))
      (fun temp_0_ round ->
          let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
            temp_0_
          in
          let round:usize = round in
          let zeta_i:usize = zeta_i -! Rust_primitives.mk_usize 1 in
          let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
            {
              re with
              Libcrux_ml_dsa.Polynomial.f_simd_units
              =
              Rust_primitives.Hax.Monomorphized_update_at.update_at_usize re
                  .Libcrux_ml_dsa.Polynomial.f_simd_units
                round
                (Libcrux_ml_dsa.Simd.Traits.f_invert_ntt_at_layer_2_ #v_SIMDUnit
                    #FStar.Tactics.Typeclasses.solve
                    (re.Libcrux_ml_dsa.Polynomial.f_simd_units.[ round ] <: v_SIMDUnit)
                    (v_ZETAS_TIMES_MONTGOMERY_R.[ zeta_i ] <: i32)
                  <:
                  v_SIMDUnit)
            }
            <:
            Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit
          in
          re, zeta_i <: (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize))
  in
  zeta_i, re <: (usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)

let invert_ntt_at_layer_3_plus
      (#v_SIMDUnit: Type0)
      (v_LAYER: usize)
      (#[FStar.Tactics.Typeclasses.tcresolve ()]
          i1:
          Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit)
      (zeta_i: usize)
      (re: Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
    : (usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
  let step:usize = Rust_primitives.mk_usize 1 <<! v_LAYER in
  let (re, zeta_i), hax_temp_output:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit &
    usize) =
    Rust_primitives.Hax.Folds.fold_range (Rust_primitives.mk_usize 0)
      (Rust_primitives.mk_usize 128 >>! v_LAYER <: usize)
      (fun temp_0_ temp_1_ ->
          let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
            temp_0_
          in
          let _:usize = temp_1_ in
          true)
      (re, zeta_i <: (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize))
      (fun temp_0_ round ->
          let re, zeta_i:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize) =
            temp_0_
          in
          let round:usize = round in
          let zeta_i:usize = zeta_i -! Rust_primitives.mk_usize 1 in
          let offset:usize =
            ((round *! step <: usize) *! Rust_primitives.mk_usize 2 <: usize) /!
            Libcrux_ml_dsa.Simd.Traits.v_COEFFICIENTS_IN_SIMD_UNIT
          in
          let step_by:usize = step /! Libcrux_ml_dsa.Simd.Traits.v_COEFFICIENTS_IN_SIMD_UNIT in
          let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
            Rust_primitives.Hax.Folds.fold_range offset
              (offset +! step_by <: usize)
              (fun re temp_1_ ->
                  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = re in
                  let _:usize = temp_1_ in
                  true)
              re
              (fun re j ->
                  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = re in
                  let j:usize = j in
                  let a_minus_b:v_SIMDUnit =
                    Libcrux_ml_dsa.Simd.Traits.f_subtract #v_SIMDUnit
                      #FStar.Tactics.Typeclasses.solve
                      (re.Libcrux_ml_dsa.Polynomial.f_simd_units.[ j +! step_by <: usize ]
                        <:
                        v_SIMDUnit)
                      (re.Libcrux_ml_dsa.Polynomial.f_simd_units.[ j ] <: v_SIMDUnit)
                  in
                  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
                    {
                      re with
                      Libcrux_ml_dsa.Polynomial.f_simd_units
                      =
                      Rust_primitives.Hax.Monomorphized_update_at.update_at_usize re
                          .Libcrux_ml_dsa.Polynomial.f_simd_units
                        j
                        (Libcrux_ml_dsa.Simd.Traits.f_add #v_SIMDUnit
                            #FStar.Tactics.Typeclasses.solve
                            (re.Libcrux_ml_dsa.Polynomial.f_simd_units.[ j ] <: v_SIMDUnit)
                            (re.Libcrux_ml_dsa.Polynomial.f_simd_units.[ j +! step_by <: usize ]
                              <:
                              v_SIMDUnit)
                          <:
                          v_SIMDUnit)
                    }
                    <:
                    Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit
                  in
                  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
                    {
                      re with
                      Libcrux_ml_dsa.Polynomial.f_simd_units
                      =
                      Rust_primitives.Hax.Monomorphized_update_at.update_at_usize re
                          .Libcrux_ml_dsa.Polynomial.f_simd_units
                        (j +! step_by <: usize)
                        (Libcrux_ml_dsa.Simd.Traits.montgomery_multiply_by_fer #v_SIMDUnit
                            a_minus_b
                            (v_ZETAS_TIMES_MONTGOMERY_R.[ zeta_i ] <: i32)
                          <:
                          v_SIMDUnit)
                    }
                    <:
                    Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit
                  in
                  re)
          in
          re, zeta_i <: (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & usize))
  in
  zeta_i, re <: (usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)

let invert_ntt_montgomery
      (#v_SIMDUnit: Type0)
      (#[FStar.Tactics.Typeclasses.tcresolve ()]
          i1:
          Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit)
      (re: Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
    : Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
  let zeta_i:usize = Libcrux_ml_dsa.Constants.v_COEFFICIENTS_IN_RING_ELEMENT in
  let tmp0, tmp1:(usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
    invert_ntt_at_layer_0_ #v_SIMDUnit zeta_i re
  in
  let zeta_i:usize = tmp0 in
  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = tmp1 in
  let _:Prims.unit = () in
  let tmp0, tmp1:(usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
    invert_ntt_at_layer_1_ #v_SIMDUnit zeta_i re
  in
  let zeta_i:usize = tmp0 in
  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = tmp1 in
  let _:Prims.unit = () in
  let tmp0, tmp1:(usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
    invert_ntt_at_layer_2_ #v_SIMDUnit zeta_i re
  in
  let zeta_i:usize = tmp0 in
  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = tmp1 in
  let _:Prims.unit = () in
  let tmp0, tmp1:(usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
    invert_ntt_at_layer_3_plus #v_SIMDUnit (Rust_primitives.mk_usize 3) zeta_i re
  in
  let zeta_i:usize = tmp0 in
  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = tmp1 in
  let _:Prims.unit = () in
  let tmp0, tmp1:(usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
    invert_ntt_at_layer_3_plus #v_SIMDUnit (Rust_primitives.mk_usize 4) zeta_i re
  in
  let zeta_i:usize = tmp0 in
  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = tmp1 in
  let _:Prims.unit = () in
  let tmp0, tmp1:(usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
    invert_ntt_at_layer_3_plus #v_SIMDUnit (Rust_primitives.mk_usize 5) zeta_i re
  in
  let zeta_i:usize = tmp0 in
  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = tmp1 in
  let _:Prims.unit = () in
  let tmp0, tmp1:(usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
    invert_ntt_at_layer_3_plus #v_SIMDUnit (Rust_primitives.mk_usize 6) zeta_i re
  in
  let zeta_i:usize = tmp0 in
  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = tmp1 in
  let _:Prims.unit = () in
  let tmp0, tmp1:(usize & Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit) =
    invert_ntt_at_layer_3_plus #v_SIMDUnit (Rust_primitives.mk_usize 7) zeta_i re
  in
  let zeta_i:usize = tmp0 in
  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = tmp1 in
  let _:Prims.unit = () in
  let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
    Rust_primitives.Hax.Folds.fold_range (Rust_primitives.mk_usize 0)
      (Core.Slice.impl__len #v_SIMDUnit
          (re.Libcrux_ml_dsa.Polynomial.f_simd_units <: t_Slice v_SIMDUnit)
        <:
        usize)
      (fun re temp_1_ ->
          let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = re in
          let _:usize = temp_1_ in
          true)
      re
      (fun re i ->
          let re:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = re in
          let i:usize = i in
          {
            re with
            Libcrux_ml_dsa.Polynomial.f_simd_units
            =
            Rust_primitives.Hax.Monomorphized_update_at.update_at_usize re
                .Libcrux_ml_dsa.Polynomial.f_simd_units
              i
              (Libcrux_ml_dsa.Simd.Traits.f_montgomery_multiply_by_constant #v_SIMDUnit
                  #FStar.Tactics.Typeclasses.solve
                  (re.Libcrux_ml_dsa.Polynomial.f_simd_units.[ i ] <: v_SIMDUnit)
                  (Rust_primitives.mk_i32 41978)
                <:
                v_SIMDUnit)
            <:
            t_Array v_SIMDUnit (Rust_primitives.mk_usize 32)
          }
          <:
          Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
  in
  re

let ntt
      (#v_SIMDUnit: Type0)
      (#[FStar.Tactics.Typeclasses.tcresolve ()]
          i1:
          Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit)
      (re: Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
    : Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
  {
    Libcrux_ml_dsa.Polynomial.f_simd_units
    =
    Libcrux_ml_dsa.Simd.Traits.f_ntt #v_SIMDUnit
      #FStar.Tactics.Typeclasses.solve
      re.Libcrux_ml_dsa.Polynomial.f_simd_units
  }
  <:
  Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit

let ntt_multiply_montgomery
      (#v_SIMDUnit: Type0)
      (#[FStar.Tactics.Typeclasses.tcresolve ()]
          i1:
          Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit)
      (lhs rhs: Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
    : Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
  let out:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
    Libcrux_ml_dsa.Polynomial.impl__ZERO #v_SIMDUnit ()
  in
  let out:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
    Rust_primitives.Hax.Folds.fold_range (Rust_primitives.mk_usize 0)
      (Core.Slice.impl__len #v_SIMDUnit
          (out.Libcrux_ml_dsa.Polynomial.f_simd_units <: t_Slice v_SIMDUnit)
        <:
        usize)
      (fun out temp_1_ ->
          let out:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = out in
          let _:usize = temp_1_ in
          true)
      out
      (fun out i ->
          let out:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit = out in
          let i:usize = i in
          {
            out with
            Libcrux_ml_dsa.Polynomial.f_simd_units
            =
            Rust_primitives.Hax.Monomorphized_update_at.update_at_usize out
                .Libcrux_ml_dsa.Polynomial.f_simd_units
              i
              (Libcrux_ml_dsa.Simd.Traits.f_montgomery_multiply #v_SIMDUnit
                  #FStar.Tactics.Typeclasses.solve
                  (lhs.Libcrux_ml_dsa.Polynomial.f_simd_units.[ i ] <: v_SIMDUnit)
                  (rhs.Libcrux_ml_dsa.Polynomial.f_simd_units.[ i ] <: v_SIMDUnit)
                <:
                v_SIMDUnit)
            <:
            t_Array v_SIMDUnit (Rust_primitives.mk_usize 32)
          }
          <:
          Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
  in
  out
