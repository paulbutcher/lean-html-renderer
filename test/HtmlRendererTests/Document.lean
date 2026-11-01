/-
Copyright (c) 2026 Paul Butcher. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
-/
module

import HtmlRendererTests.Elems
meta import HtmlRendererTests.Elems

namespace HtmlRendererTests

open Html

#guard document (head (title "T")) (body [])
  = "<!DOCTYPE html><html><head><title>T</title></head><body></body></html>"
#guard document (head (title "T")) (body []) (lang := "en")
  = "<!DOCTYPE html><html lang=\"en\"><head><title>T</title></head><body></body></html>"
#guard document (head (title "T")) (body [p [Node.text "hi"]])
  = "<!DOCTYPE html><html><head><title>T</title></head><body><p>hi</p></body></html>"
#guard document (head (title "T") [meta_ [.value "charset" "utf-8"]]) (body [])
  = "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>T</title></head><body></body></html>"
#guard document (head (title "<script>")) (body [])
  = "<!DOCTYPE html><html><head><title>&lt;script&gt;</title></head><body></body></html>"

#guard document (head (title "T")) (body []) (pretty := true)
  = "<!DOCTYPE html>\n<html>\n  <head>\n    <title>T</title>\n  </head>\n  <body></body>\n</html>"
#guard document (head (title "T")) (body [p [Node.text "hi"]]) (pretty := true) (unit := "    ")
  = "<!DOCTYPE html>\n<html>\n    <head>\n        <title>T</title>\n    </head>\n" ++
    "    <body>\n        <p>hi</p>\n    </body>\n</html>"

-- Nothing in `<head>` renders, so each of its children has a line of its own, though `meta` is
-- phrasing content in the body.
#guard document (head (title "T") [meta_ [.value "charset" "utf-8"], meta_ [.value "name" "x"]])
    (body [p [Node.text "a", meta_ [.value "itemprop" "x"]]]) (pretty := true)
  = "<!DOCTYPE html>\n<html>\n  <head>\n    <meta charset=\"utf-8\">\n" ++
    "    <meta name=\"x\">\n    <title>T</title>\n  </head>\n" ++
    "  <body>\n    <p>a<meta itemprop=\"x\"></p>\n  </body>\n</html>"
#guard Node.render (head (title "T") [meta_ [.value "charset" "utf-8"], meta_ [.value "name" "x"]])
    (lineBreaks := true)
  = "<head>\n<meta charset=\"utf-8\">\n<meta name=\"x\">\n<title>T</title>\n</head>"

#guard document (head (title "T") [meta_ [.value "charset" "utf-8"]]) (body []) (dialect := .xhtml)
  = "<!DOCTYPE html><html xmlns=\"http://www.w3.org/1999/xhtml\">" ++
    "<head><meta charset=\"utf-8\" /><title>T</title></head><body></body></html>"
#guard document (head (title "T")) (body []) (lang := "en") (dialect := .xhtml)
  = "<!DOCTYPE html><html xmlns=\"http://www.w3.org/1999/xhtml\" lang=\"en\" xml:lang=\"en\">" ++
    "<head><title>T</title></head><body></body></html>"
#guard document (head (title "T"))
    (body [input [.value "type" "checkbox", .flag "checked"]]) (dialect := .xhtml)
  = "<!DOCTYPE html><html xmlns=\"http://www.w3.org/1999/xhtml\"><head><title>T</title></head>" ++
    "<body><input type=\"checkbox\" checked=\"checked\" /></body></html>"

end HtmlRendererTests
