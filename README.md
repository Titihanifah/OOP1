# tubes-1
OOP

tutorial msysgit : http://techylab.com/761/setting-up-git-work-environment-on-windows/


Jika sudah berhasil clone repo github ke sebuah direktori di komputer kita (baca tutorial di atas),
maka kita bisa mulai menggunakannya.
Langkah-langkah sinkronisasi file menggunakan Git GUI, jika kita ingin sinkronisasi file:
1. Remote->fetch from -> origin (untuk mendapatkan update terbaru file dari repo di github.com)
2. Merge -> local merge (ini akan mengsinkronisasikan file-file di direktori komputer kita sama persis dengan di github,
melalui update-an yg kita dapat dari proses "fetch from")
2. Rescan ( memeriksa file mana saja yang kita ubah)
3. Stage Changed ( konfirmasi bahwa file -file tersebut memang kita ubah)
4. Commit (mengkonfirmasi perubahan di stage changed, belum sampai ke repo di github)
5. Push (mengupdate repo kita di github dengan commit yang sudah kita buat). Akan ada permintaan
	username dan password kita di github.

Jika success, maka otomatis file-file di repo github akan sama persis dengan
file-file yang ada di direktori komputer kita.

//test

