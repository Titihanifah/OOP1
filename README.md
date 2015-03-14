# tubes 1 OOP - Kalkulator

***TUTORIAL git dan GitHub***

//REFERENSI

tutorial install msysgit dan clone repo : http://techylab.com/761/setting-up-git-work-environment-on-windows/

dokumentasi resmi git : http://git-scm.com/docs


//CARA SINKRONISASI FILE DI KOMPUTER KITA DENGAN GITHUB

Jika sudah berhasil clone repo github ke sebuah direktori di komputer kita (baca tutorial di atas),
maka kita bisa mulai sinkronisasi.

Langkah-langkah sinkronisasi menggunakan Git GUI:


1. Remote->fetch from -> origin (untuk mendapatkan update terbaru file dari repo di github.com)

2. Merge -> local merge (ini akan mengsinkronisasikan file-file di direktori komputer kita sama persis dengan di github,
melalui update-an yg kita dapat dari proses "fetch from")

3. Rescan ( memeriksa file mana saja yang kita ubah)

4. Stage Changed ( konfirmasi bahwa file -file tersebut memang kita ubah)

5. Commit (mengkonfirmasi perubahan di stage changed, belum sampai ke repo di github)

6. Push (mengupdate repo kita di github dengan commit yang sudah kita buat). Akan ada permintaan
	username dan password kita di github.

Jika success, maka otomatis file-file di repo github akan sama persis dengan
file-file yang ada di direktori komputer kita.


*** Hindari pengeditan file yang sama secara berbarengan, bisa conflict.

Ada cara resolvenya, cuma ntar jadi agak repot. 

Jadi lebih baik dibagi" tugasnya *** TERIMA KASIH

NB: Kalau ada pertanyaan lewat FB atau LINE. Tapi ga yakin bisa gw jawab semua,
 sama-sama masih belajar. Selamat mencoba ! LOL...
