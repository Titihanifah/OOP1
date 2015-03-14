# tubes 1 OOP - Kalkulator

***TUTORIAL git dan GitHub***

//REFERENSI

tutorial install msysgit dan clone repo : http://techylab.com/761/setting-up-git-work-environment-on-windows/

dokumentasi resmi git : http://git-scm.com/docs


//CARA SINKRONISASI FILE DI KOMPUTER KITA DENGAN GITHUB

Jika sudah berhasil clone repo github ke sebuah direktori di komputer kita (baca tutorial di atas),
maka kita bisa mulai sinkronisasi.

Pertama-tama, lakukan pengeditan file-file berisi kode seperti biasa, tanpa perlu buka Git GUI.

Setelah selesai lakukan pengeditan, sinkronisasi dengan github sebagai berikut

Langkah-langkah sinkronisasi menggunakan Git GUI:

1. Remote->fetch from -> origin (untuk mendapatkan update terbaru file dari repo di github.com)

2. Merge -> local merge. Jika "radio button" ada di revision expression, berarti belum ada perubahan di github, skip langkah 2 ini, pilih cancel. 
Jika ada tracking branch, maka pilih Merge. (ini akan mengsinkronisasikan file-file di direktori komputer kita sama persis dengan di github,
melalui update-an yg kita dapat dari proses "fetch from". Akan tetapi file" kode yang barusan kita edit
di komputer kita tidak akan ter-replace oleh file dari github. Hal ini karena ada pencatatan perubahan
terakhir yang dilakukan (mungkin...). Conflict ? ->baca ket. di paling bawah  )

3. Rescan ( memeriksa file mana saja yang kita ubah)

4. Stage Changed ( konfirmasi bahwa file -file tersebut memang kita ubah)

5. Commit (mengkonfirmasi perubahan di stage changed, belum sampai ke repo di github)

6. Push (mengupdate repo kita di github dengan commit yang sudah kita buat). Akan ada permintaan
	username dan password kita di github.

Jika success, maka otomatis file-file di repo github akan sama persis dengan
file-file yang ada di direktori komputer kita.


TERIMA KASIH

***Ket conflict*** : Conflict akan terjadi jika seseorang mengubah suatu file misal file X dan sudah commit/push
ke github, lalu kita mengedit file X di komputer kita, yg belum tersinkronisasi dengan pengeditan yang dilakukan "seseorang" tersebut. Ini akan membingungkan
git, versi pengeditan mana yang dipakai. Jadi harus ada merge resolution (tidak dijelaskan di sini, terlalu panjang).
Maka hindari pengeditan suatu file yang berbarengan.

***SARAN*** : Ada baiknya memiliki backup di luar direktori git kita, kalau" hilang.

NB: Tutorial dibuat setelah coba-coba pake. Kalau ada pertanyaan / kesalahan  bisa lewat FB atau LINE. Tapi ga yakin bisa gw jawab semua,
 sama-sama masih belajar. Selamat mencoba ! LOL...