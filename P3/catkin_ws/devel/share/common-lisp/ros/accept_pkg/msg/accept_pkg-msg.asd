
(cl:in-package :asdf)

(defsystem "accept_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "xyz" :depends-on ("_package_xyz"))
    (:file "_package_xyz" :depends-on ("_package"))
  ))